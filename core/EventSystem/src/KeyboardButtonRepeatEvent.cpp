#include <EventSystem/Events/KeyboardButtonRepeatEvent.hpp>

namespace VoxelEngine {

KeyboardButtonRepeatEvent::KeyboardButtonRepeatEvent(KeyCode button)
    : button(button) {}

std::string KeyboardButtonRepeatEvent::format() const {
  return name + ": " + std::to_string(static_cast<std::size_t>(button));
}

std::string KeyboardButtonRepeatEvent::Name() const { return name; }

Event::EventType KeyboardButtonRepeatEvent::Type() const { return type; }

const std::string KeyboardButtonRepeatEvent::name = "Keyboard button repeat";
const Event::EventType KeyboardButtonRepeatEvent::type =
    Event::EventType::KEYBOARD_KEY_REPEAT;

}  // namespace VoxelEngine