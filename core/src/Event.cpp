#include "private/Event.hpp"
#include "public/Keys.hpp"

#include <cstdint>
#include <string>
#include <array>
#include <functional>

namespace VoxelEngine {

//TODO: разнести по файлам

MouseMoveEvent::MouseMoveEvent(double x, double y)
    :
    x(x),
    y(y) {}

std::string MouseMoveEvent::format() const {
    return name + ": " + std::to_string(x) + " " + std::to_string(y);
}

std::string MouseMoveEvent::Name() const { return name; }

Event::EventType MouseMoveEvent::Type() const { return type; }

std::pair<double, double> MouseMoveEvent::Data() const {
  return std::pair(x, y);
}

const std::string MouseMoveEvent::name = "Mouse move";
const Event::EventType MouseMoveEvent::type = Event::EventType::MOUSE_MOVE;


MouseButtonPressEvent::MouseButtonPressEvent(KeyCode button)
  : button(button) {}

std::string MouseButtonPressEvent::format() const {
    return name + ": " + std::to_string(static_cast<std::size_t>(button));
}

std::string MouseButtonPressEvent::Name() const { return name; }

Event::EventType MouseButtonPressEvent::Type() const { return type; }

const std::string MouseButtonPressEvent::name = "Mouse button press";
const Event::EventType MouseButtonPressEvent::type = Event::EventType::MOUSE_BUTTON_PRESS;


MouseButtonReleaseEvent::MouseButtonReleaseEvent(KeyCode button)
  : button(button) {}

std::string MouseButtonReleaseEvent::format() const {
    return name + ": " + std::to_string(static_cast<std::size_t>(button));
}

std::string MouseButtonReleaseEvent::Name() const { return name; }

Event::EventType MouseButtonReleaseEvent::Type() const { return type; }

const std::string MouseButtonReleaseEvent::name = "Mouse button release";
const Event::EventType MouseButtonReleaseEvent::type = Event::EventType::MOUSE_BUTTON_RELEASE;

KeyboardButtonPressEvent::KeyboardButtonPressEvent(KeyCode button)
  : button(button) {}

std::string KeyboardButtonPressEvent::format() const {
    return name + ": " + std::to_string(static_cast<std::size_t>(button));
}

std::string KeyboardButtonPressEvent::Name() const { return name; }

Event::EventType KeyboardButtonPressEvent::Type() const { return type; }

const std::string KeyboardButtonPressEvent::name = "Keyboard button press";
const Event::EventType KeyboardButtonPressEvent::type = Event::EventType::KEYBOARD_KEY_PRESS;

KeyboardButtonReleaseEvent::KeyboardButtonReleaseEvent(KeyCode button)
  : button(button) {}

std::string KeyboardButtonReleaseEvent::format() const {
    return name + ": " + std::to_string(static_cast<std::size_t>(button));
}

std::string KeyboardButtonReleaseEvent::Name() const { return name; }

Event::EventType KeyboardButtonReleaseEvent::Type() const { return type; }

const std::string KeyboardButtonReleaseEvent::name = "Keyboard button release";
const Event::EventType KeyboardButtonReleaseEvent::type = Event::EventType::KEYBOARD_KEY_RELEASE;

KeyboardButtonRepeatEvent::KeyboardButtonRepeatEvent(KeyCode button)
  : button(button) {}

std::string KeyboardButtonRepeatEvent::format() const {
    return name + ": " + std::to_string(static_cast<std::size_t>(button));
}

std::string KeyboardButtonRepeatEvent::Name() const { return name; }

Event::EventType KeyboardButtonRepeatEvent::Type() const { return type; }

const std::string KeyboardButtonRepeatEvent::name = "Keyboard button repeat";
const Event::EventType KeyboardButtonRepeatEvent::type = Event::EventType::KEYBOARD_KEY_REPEAT;

}  // namespace VoxelEngine