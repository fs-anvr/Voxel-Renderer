#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <functional>

#include <glm/glm.hpp>

#include "Camera.hpp"
#include "Renderer.hpp"
#include "ShaderProgram.hpp"
#include "VoxelModel.hpp"
#include "Event.hpp"

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

 private:
  bool Init();

  Window(const Window&) = delete;
  Window(Window&&) = delete;
  Window& operator=(const Window&) = delete;
  Window& operator=(Window&&) = delete;

  // TODO: вынести всё состояние, не относящиеся к окну

  uint16_t _width;
  uint16_t _height;
  std::string _title;
  EventCallback _eventCallback;

  GLFWwindow* _window;
  bool _isInitialized;  // костыль?

  ShaderProgram _shaderProgram;  // костыль?

  VoxelModel _model;   // костыль?
  Renderer _renderer;  // костыль?
  Camera _camera;      // костыль?
};

}  // namespace VoxelEngine