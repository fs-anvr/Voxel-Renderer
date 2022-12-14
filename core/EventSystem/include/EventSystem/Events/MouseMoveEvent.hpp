#pragma once

#include <EventSystem/Events/Event.hpp>

namespace VoxelEngine {

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

}  // namespace VoxelEngine