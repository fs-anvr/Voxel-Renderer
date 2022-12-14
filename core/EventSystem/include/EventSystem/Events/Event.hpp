#pragma once

#include <Input/Keys.hpp>
#include <array>
#include <cstdint>
#include <functional>
#include <string>
#include <tuple>

namespace VoxelEngine {

class Event {
 public:
  enum class EventType : std::uint8_t {
    KEYBOARD_KEY_PRESS = 1,
    KEYBOARD_KEY_RELEASE,
    KEYBOARD_KEY_REPEAT,

    MOUSE_MOVE,
    MOUSE_BUTTON_PRESS,
    MOUSE_BUTTON_RELEASE,

    EVENTS_COUNT
  };

  virtual ~Event() = default;

  virtual std::string Name() const = 0;

  virtual EventType Type() const = 0;

  virtual std::string format() const = 0;

 protected:
  Event() = default;
};

}  // namespace VoxelEngine