// clang-format off

#include <App/Window.hpp>

#include <ServiceLocator/ServiceLocator.hpp>
#include <EventSystem/EventSystem.hpp>
#include <Input/Input.hpp>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <cstdint>
#include <iostream>
#include <string>

// clang-format on

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
    ServiceLocator::Renderer().Rerender();

    glfwSwapBuffers(_window);
    glfwPollEvents();
    glfwSwapInterval(1);
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

    glfwMakeContextCurrent(_window);
    glfwSetWindowUserPointer(_window, this);

    if (gladLoadGL(static_cast<GLADloadfunc>(glfwGetProcAddress)) == false) {
      std::cout << "GLAD LOAD ISSUE" << std::endl;
      return false;
    }

    glfwSetCursorPosCallback(_window, mouseMoveCallback);
    glfwSetMouseButtonCallback(_window, mouseButtonCallback);
    glfwSetKeyCallback(_window, keyboardButtonCallback);

    return true;
  }

  void Window::setCallback(EventCallback callback) { _eventCallback = callback; }


  void Window::mouseMoveCallback(GLFWwindow* window, double xPos, double yPos) {
    auto& handle = *static_cast<Window*>(glfwGetWindowUserPointer(window));
    MouseMoveEvent event(xPos, yPos);
    handle._eventCallback(event);
  }

  void Window::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    auto& handle = *static_cast<Window*>(glfwGetWindowUserPointer(window));
    KeyCode buttonCode;

    switch (button)
    {
    case GLFW_MOUSE_BUTTON_RIGHT:
      buttonCode = KeyCode::MOUSE_RIGHT_BUTTON;
      break;
    
    default:
      buttonCode = KeyCode::KEYS_COUNT;
      break;
    }

    if (action == GLFW_PRESS) {
      MouseButtonPressEvent event(buttonCode);
      handle._eventCallback(event);
    } else if (action == GLFW_RELEASE) {
      MouseButtonReleaseEvent event(buttonCode);
      handle._eventCallback(event);
    }
  }

  void Window::keyboardButtonCallback(GLFWwindow* window, int button, int scancode, int action, int mods) {
    auto& handle = *static_cast<Window*>(glfwGetWindowUserPointer(window));
    KeyCode buttonCode;

    switch (button) {
    case GLFW_KEY_UP:
      buttonCode = KeyCode::KEYBOARD_UPARROW;
      break;

    case GLFW_KEY_DOWN:
      buttonCode = KeyCode::KEYBOARD_DOWNARROW;
      break;

    case GLFW_KEY_RIGHT:
      buttonCode = KeyCode::KEYBOARD_RIGHTARROW;
      break;

    case GLFW_KEY_LEFT:
      buttonCode = KeyCode::KEYBOARD_LEFTARROW;
      break;
    
    default:
      buttonCode = KeyCode::KEYS_COUNT;
      break;
    }

    switch (action) {
    case GLFW_PRESS:
      {
        KeyboardButtonPressEvent event(buttonCode);
        handle._eventCallback(event);
      }
      break;

    case GLFW_RELEASE:
      {
        KeyboardButtonReleaseEvent event(buttonCode);
        handle._eventCallback(event);
      }
      break;

    case GLFW_REPEAT:
      {
        KeyboardButtonRepeatEvent event(buttonCode);
        handle._eventCallback(event);
      }
      break;
    
    default:
      break;
    }
  }

}  // namespace VoxelEngine