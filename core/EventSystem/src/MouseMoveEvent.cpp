#include <EventSystem/Events/MouseMoveEvent.hpp>

namespace VoxelEngine {

MouseMoveEvent::MouseMoveEvent(double x, double y) : x(x), y(y) {}

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

}  // namespace VoxelEngine