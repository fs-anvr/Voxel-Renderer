#pragma once

#include <cstdint>
#include <string>
#include <array>

namespace VoxelEngine {

class Event {
 public:
  enum class EventType : std::uint8_t {
    KEYBOARD_KEY_PRESS = 1,
    KEYBOARD_KEY_RELEASE,
    KEYBOARD_KEY_REPEAT,

    MOUSE_MOVE,
    MOUSE_BUTTON_PRESS,
    MOUSE_BUTTON_RELEASE,

    EVENTS_COUNT, //  работает только при непрерывных значениях членов, начинающихся с 1
    BASE_EVENT
  };

  virtual ~Event() = default;

  virtual std::string Name() const = 0;

  virtual EventType Type() const = 0;

  virtual std::string format() const = 0;

 protected:
  Event() = default;
};

class MouseMoveEvent : public Event {
 public:
  MouseMoveEvent(double x, double y)
    :
    x(x),
    y(y) {}

  ~MouseMoveEvent() override = default;

  std::string format() const override {
    return name + ": " + std::to_string(x) + " " + std::to_string(y);
  }

  std::string Name() const override { return name; }

  EventType Type() const override { return type; }

  static const std::string name;
  static const Event::EventType type;

 private:
  double x, y;
};

const std::string MouseMoveEvent::name = "Mouse move";
const Event::EventType MouseMoveEvent::type = Event::EventType::MOUSE_MOVE;


class MouseButtonPressEvent : public Event {
 public:
  MouseButtonPressEvent(int button, int action, int mods)
    :
    button(button),
    action(action),
    mods(mods) {}

  ~MouseButtonPressEvent() override = default;

  std::string format() const override {
    return name + ": " + std::to_string(button) + " " + std::to_string(action);
  }

  std::string Name() const override { return name; }

  EventType Type() const override { return type; }

  static const std::string name;
  static const Event::EventType type;

 private:
  int button;
  int action;
  int mods;
};

const std::string MouseButtonPressEvent::name = "Mouse button press";
const Event::EventType MouseButtonPressEvent::type = Event::EventType::MOUSE_BUTTON_PRESS;

class MouseButtonReleaseEvent : public Event {
 public:
  MouseButtonReleaseEvent(int button, int action, int mods)
    :
    button(button),
    action(action),
    mods(mods) {}

  ~MouseButtonReleaseEvent() override = default;

  std::string format() const override {
    return name + ": " + std::to_string(button) + " " + std::to_string(action);
  }

  std::string Name() const override { return name; }

  EventType Type() const override { return type; }

  static const std::string name;
  static const Event::EventType type;

 private:
  int button;
  int action;
  int mods;
};

const std::string MouseButtonReleaseEvent::name = "Mouse button release";
const Event::EventType MouseButtonReleaseEvent::type = Event::EventType::MOUSE_BUTTON_RELEASE;

//TODO: concepts для template AddListener

class EventDispatcher {
  using EventCallback = std::function<void(Event&)>;
 public:
  template <typename EventType>
  void AddListener(std::function<void(EventType&)> callback) {
    auto basedCallback = [func = callback](Event& event) {
      func(static_cast<EventType&>(event));
    };
    callbacks[static_cast<std::size_t>(EventType::type)] = std::move(basedCallback);
  }

  void Dispatch(Event& event) {
    auto& callback = callbacks[static_cast<std::size_t>(event.Type())];
    if (callback) {
      callback(event);
    }
  }
 private:
  std::array<EventCallback, static_cast<std::size_t>(Event::EventType::EVENTS_COUNT)> callbacks;
};

}  // namespace VoxelEngine