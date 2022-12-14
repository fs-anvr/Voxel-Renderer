#include <EventSystem/Events/KeyboardButtonPressEvent.hpp>

namespace VoxelEngine {

KeyboardButtonPressEvent::KeyboardButtonPressEvent(KeyCode button)
    : button(button) {}

std::string KeyboardButtonPressEvent::format() const {
  return name + ": " + std::to_string(static_cast<std::size_t>(button));
}

std::string KeyboardButtonPressEvent::Name() const { return name; }

Event::EventType KeyboardButtonPressEvent::Type() const { return type; }

const std::string KeyboardButtonPressEvent::name = "Keyboard button press";
const Event::EventType KeyboardButtonPressEvent::type =
    Event::EventType::KEYBOARD_KEY_PRESS;

}  // namespace VoxelEngine