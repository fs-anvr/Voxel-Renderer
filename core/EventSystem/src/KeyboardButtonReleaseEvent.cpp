#include <EventSystem/Events/KeyboardButtonReleaseEvent.hpp>

namespace VoxelEngine {

KeyboardButtonReleaseEvent::KeyboardButtonReleaseEvent(KeyCode button)
  : button(button) {}

std::string KeyboardButtonReleaseEvent::format() const {
    return name + ": " + std::to_string(static_cast<std::size_t>(button));
}

std::string KeyboardButtonReleaseEvent::Name() const { return name; }

Event::EventType KeyboardButtonReleaseEvent::Type() const { return type; }

const std::string KeyboardButtonReleaseEvent::name = "Keyboard button release";
const Event::EventType KeyboardButtonReleaseEvent::type = Event::EventType::KEYBOARD_KEY_RELEASE;

}  // namespace VoxelEngine