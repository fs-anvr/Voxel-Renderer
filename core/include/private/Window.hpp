#pragma once

// clang-format off

#include <EventSystem/EventSystem.hpp>
#include <Shaders/ShaderProgram.hpp>
#include <Voxel/VoxelModel.hpp>
#include <Render/Renderer.hpp>

#include <glm/glm.hpp>

#include <cstdint>
#include <functional>
#include <string>
#include <vector>

// clang-format on

class GLFWwindow;
typedef unsigned int GLuint;

namespace VoxelEngine {

class Window {
  using EventCallback = std::function<void(Event&)>;
 public:

  Window(uint16_t width, uint16_t height, std::string title);
  ~Window();

  void Update();

  int ShoudBeClose();

  uint16_t Width() const { return _width; }
  uint16_t Height() const { return _height; }
  std::string Title() const { return _title; }
  bool IsInitialized() const { return _isInitialized; }

  void setCallback(EventCallback callback);

  static void mouseMoveCallback(GLFWwindow* window, double x, double y);

  static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

  static void keyboardButtonCallback(GLFWwindow* window, int button, int scancode, int action, int mods);

 private:
  bool Init();

  Window(const Window&) = delete;
  Window(Window&&) = delete;
  Window& operator=(const Window&) = delete;
  Window& operator=(Window&&) = delete;

  uint16_t _width;
  uint16_t _height;
  std::string _title;
  EventCallback _eventCallback;

  GLFWwindow* _window;
  bool _isInitialized;  // костыль?
};

}  // namespace VoxelEngine