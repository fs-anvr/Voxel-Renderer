#include <iostream>
#include <cstdint>
#include <string>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "Window.hpp"

namespace VoxelEngine {

  Window::Window(uint16_t width, uint16_t height, std::string title)
    : _width(width), _height(height), _title(title) {
      _isInitialized = Init();
    }

  Window::~Window() {
    glfwDestroyWindow(_window);
    glfwTerminate();
  }

  void Window::Update() {
    glClearColor(0.8, 0.8, 0.8, 0.1);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(_window);
    glfwPollEvents();
    /* Loop until the user closes the window */
    // while (!glfwWindowShouldClose(_window)) {}
  }

  int Window::ShoudBeClose() {
    return glfwWindowShouldClose(_window);
  }

  bool Window::Init() {
    if (!glfwInit()) return false;

    _window = glfwCreateWindow(_width, _height, _title.c_str(), nullptr, nullptr);
    if (_window == nullptr) {
      glfwTerminate();
      return false;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(_window);

    if (gladLoadGL(static_cast<GLADloadfunc>(glfwGetProcAddress)) == false) {
      std::cout << "GLAD LOAD ISSUE" << std::endl;
    }

    return true;
  }

}  // namespace VoxelEngine