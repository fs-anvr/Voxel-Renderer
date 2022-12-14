#pragma once

#include <EventSystem/Events/Event.hpp>

namespace VoxelEngine {

//TODO: concepts для template AddListener

class EventDispatcher {
  using EventCallback = std::function<void(Event&)>;
 public:
  template <typename EventType>
  void AddListener(std::function<void(EventType&)> callback) {
    auto basedCallback = [func = callback](Event& event) {
      func(static_cast<EventType&>(event));
    };
    callbacks[static_cast<std::size_t>(EventType::type)] = std::move(basedCallback);
  }

  void Dispatch(Event& event);
 private:
  std::array<EventCallback, static_cast<std::size_t>(Event::EventType::EVENTS_COUNT)> callbacks;
};

}  // namespace VoxelEngine