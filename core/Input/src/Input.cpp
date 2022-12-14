#include <Input/Input.hpp>
#include <cstdint>

namespace VoxelEngine {

std::array<KeyState, static_cast<std::size_t>(KeyCode::KEYS_COUNT)> Input::keys;

KeyState Input::GetState(KeyCode key) {
  return keys[static_cast<std::size_t>(key)];
}

bool Input::IsPressed(KeyCode key) {
  return keys[static_cast<std::size_t>(key)] == KeyState::PRESS;
}

bool Input::IsReleased(KeyCode key) {
  return keys[static_cast<std::size_t>(key)] == KeyState::RELEASE;
}

bool Input::IsRepeated(KeyCode key) {
  return keys[static_cast<std::size_t>(key)] == KeyState::REPEAT;
}

void Input::PressKey(KeyCode key) {
  keys[static_cast<std::size_t>(key)] = KeyState::PRESS;
}

void Input::ReleaseKey(KeyCode key) {
  keys[static_cast<std::size_t>(key)] = KeyState::RELEASE;
}

void Input::RepeatKey(KeyCode key) {
  keys[static_cast<std::size_t>(key)] = KeyState::REPEAT;
}

void Input::Mouse::SetPos(double x, double y) { pos = std::pair(x, y); }

void Input::Mouse::SetDeltaPos(double x, double y) {
  deltaPos = std::pair(x, y);
}

Input::Mouse::vec2 Input::Mouse::pos = std::pair(0.0, 0.0);
Input::Mouse::vec2 Input::Mouse::deltaPos = std::pair(0.0, 0.0);

Input::Mouse::vec2 Input::Mouse::GetPos() { return pos; }

Input::Mouse::vec2 Input::Mouse::GetDeltaPos() { return deltaPos; }

void Input::Mouse::ShowCursor() {
  // glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Input::Mouse::HideCursor() {
  // glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

}  // namespace VoxelEngine
