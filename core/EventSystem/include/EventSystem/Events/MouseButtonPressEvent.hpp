#pragma once

#include <EventSystem/Events/Event.hpp>

namespace VoxelEngine {

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

}  // namespace VoxelEngine