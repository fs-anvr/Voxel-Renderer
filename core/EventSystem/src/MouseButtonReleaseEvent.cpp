#include <EventSystem/Events/MouseButtonReleaseEvent.hpp>

namespace VoxelEngine {

MouseButtonReleaseEvent::MouseButtonReleaseEvent(KeyCode button)
    : button(button) {}

std::string MouseButtonReleaseEvent::format() const {
  return name + ": " + std::to_string(static_cast<std::size_t>(button));
}

std::string MouseButtonReleaseEvent::Name() const { return name; }

Event::EventType MouseButtonReleaseEvent::Type() const { return type; }

const std::string MouseButtonReleaseEvent::name = "Mouse button release";
const Event::EventType MouseButtonReleaseEvent::type =
    Event::EventType::MOUSE_BUTTON_RELEASE;

}  // namespace VoxelEngine