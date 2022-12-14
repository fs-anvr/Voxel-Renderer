#pragma once

#include <EventSystem/Events/Event.hpp>

namespace VoxelEngine {

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

}  // namespace VoxelEngine