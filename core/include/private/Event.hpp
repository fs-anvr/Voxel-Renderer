#pragma once

#include "public/Keys.hpp"

#include <cstdint>
#include <string>
#include <array>
#include <functional>
#include <tuple>

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

    EVENTS_COUNT //  работает только при непрерывных значениях членов, начинающихся с 1
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
  MouseMoveEvent(double x, double y);

  ~MouseMoveEvent() override = default;

  std::string format() const override;

  std::string Name() const override;

  EventType Type() const override;

  std::pair<double, double> Data() const;

  static const std::string name;
  static const Event::EventType type;

 private:
  double x, y;
};


class MouseButtonPressEvent : public Event {
 public:
  MouseButtonPressEvent(KeyCode button);

  ~MouseButtonPressEvent() override = default;

  std::string format() const override;

  std::string Name() const override;

  EventType Type() const override;

  static const std::string name;
  static const Event::EventType type;
  const KeyCode button;
};

class MouseButtonReleaseEvent : public Event {
 public:
  MouseButtonReleaseEvent(KeyCode button);

  ~MouseButtonReleaseEvent() override = default;

  std::string format() const override;

  std::string Name() const override;

  EventType Type() const override;

  static const std::string name;
  static const Event::EventType type;
  const KeyCode button;
};

class KeyboardButtonPressEvent : public Event {
 public:
  KeyboardButtonPressEvent(KeyCode button);

  ~KeyboardButtonPressEvent() override = default;

  std::string format() const override;

  std::string Name() const override;

  EventType Type() const override;

  static const std::string name;
  static const Event::EventType type;
  const KeyCode button;
};

class KeyboardButtonReleaseEvent : public Event {
 public:
  KeyboardButtonReleaseEvent(KeyCode button);

  ~KeyboardButtonReleaseEvent() override = default;

  std::string format() const override;

  std::string Name() const override;

  EventType Type() const override;

  static const std::string name;
  static const Event::EventType type;
  const KeyCode button;
};

class KeyboardButtonRepeatEvent : public Event {
 public:
  KeyboardButtonRepeatEvent(KeyCode button);

  ~KeyboardButtonRepeatEvent() override = default;

  std::string format() const override;

  std::string Name() const override;

  EventType Type() const override;

  static const std::string name;
  static const Event::EventType type;
  const KeyCode button;
};

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