#include <EventSystem/EventDispatcher.hpp>

namespace VoxelEngine {

void EventDispatcher::Dispatch(Event& event) {
  auto& callback = callbacks[static_cast<std::size_t>(event.Type())];
  if (callback) {
    callback(event);
  }
}

}  // namespace VoxelEngine