#pragma once

namespace VoxelEngine {

enum class KeyCode {
  KEYBOARD_UPARROW = 1,
  KEYBOARD_DOWNARROW,
  KEYBOARD_RIGHTARROW,
  KEYBOARD_LEFTARROW,

  MOUSE_RIGHT_BUTTON,

  KEYS_COUNT
};

enum class KeyState {
  PRESS = 1,
  RELEASE,
  REPEAT,

  STATE_COUNT
};

}  // namespace VoxelEngine