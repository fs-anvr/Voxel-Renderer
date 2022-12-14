#include <EventSystem/EventDispatcher.hpp>

namespace VoxelEngine {

//TODO: concepts для template AddListener

/*template <typename EventType>
void EventDispatcher::AddListener(std::function<void(EventType&)> callback) {
  auto basedCallback = [func = callback](Event& event) {
    func(static_cast<EventType&>(event));
  };
  callbacks[static_cast<std::size_t>(EventType::type)] = std::move(basedCallback);
}*/

void EventDispatcher::Dispatch(Event& event) {
  auto& callback = callbacks[static_cast<std::size_t>(event.Type())];
  if (callback) {
    callback(event);
  }
}

}  // namespace VoxelEngine