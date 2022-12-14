#include <EventSystem/Events/MouseButtonPressEvent.hpp>

namespace VoxelEngine {

MouseButtonPressEvent::MouseButtonPressEvent(KeyCode button) : button(button) {}

std::string MouseButtonPressEvent::format() const {
  return name + ": " + std::to_string(static_cast<std::size_t>(button));
}

std::string MouseButtonPressEvent::Name() const { return name; }

Event::EventType MouseButtonPressEvent::Type() const { return type; }

const std::string MouseButtonPressEvent::name = "Mouse button press";
const Event::EventType MouseButtonPressEvent::type =
    Event::EventType::MOUSE_BUTTON_PRESS;

}  // namespace VoxelEngine