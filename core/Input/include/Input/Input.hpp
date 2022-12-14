#pragma once

#include <Input/Keys.hpp>
#include <array>
#include <cstdint>

namespace VoxelEngine {

class Input {
 public:
  static KeyState GetState(KeyCode key);

  static bool IsPressed(KeyCode key);

  static bool IsReleased(KeyCode key);

  static bool IsRepeated(KeyCode key);

  static void PressKey(KeyCode key);

  static void ReleaseKey(KeyCode key);

  static void RepeatKey(KeyCode key);

  class Mouse {
    using vec2 = std::pair<double, double>;

   public:
    static void SetPos(double x, double y);
    static void SetDeltaPos(double x, double y);

    static vec2 GetPos();
    static vec2 GetDeltaPos();

    static void ShowCursor();
    static void HideCursor();

   private:
    Mouse() = delete;
    ~Mouse() = delete;
    static vec2 pos;
    static vec2 deltaPos;
  };

 private:
  static std::array<KeyState, static_cast<std::size_t>(KeyCode::KEYS_COUNT)>
      keys;
};

}  // namespace VoxelEngine
