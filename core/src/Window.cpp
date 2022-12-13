#include "private/Window.hpp"

#include <GLFW/glfw3.h>
#include <glad/gl.h>

#include <cstdint>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <string>

#include "private/Camera.hpp"
#include "private/Renderer.hpp"
#include "private/ShaderProgram.hpp"
#include "private/VoxelModel.hpp"
#include "private/Event.hpp"
#include "public/Input.hpp"

#include "public/ServiceLocator.hpp"

namespace VoxelEngine {

// TODO: вынести лишний код из Window
// TODO: вынести камеру / клаву / мышь

void ProcessInputKeyboard(GLFWwindow* window, Camera* camera) {
  const float speed = 5 * 0.01;//  * deltaTime;  // double doesn't work

  if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
    camera->position += speed * camera->Direction();
  }
  if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
    camera->position -= speed * camera->Direction();
  }
  if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
    camera->position += speed * glm::normalize(camera->Right());
  }
  if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
    camera->position -= speed * glm::normalize(camera->Right());
  }
}

Window::Window(uint16_t width, uint16_t height, std::string title)
  : _width(width), _height(height), _title(title) {
  _isInitialized = Init();
  }

  Window::~Window() {
    glfwDestroyWindow(_window);
    glfwTerminate();
  }

  void Window::Update() {
    /* clear */
    
    glClearColor(0.1, 0.1, 0.1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //ProcessInputKeyboard(this->_window, &_camera);

    Camera& camera = ServiceLocator::Camera();

    glm::mat4 MVP = camera.Projection() * camera.View() * _model.transform;

    static GLuint MatrixID = glGetUniformLocation(_shaderProgram.id, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

    glUseProgram(_shaderProgram.id);

    _renderer.Render(_model);
    //_renderer.Render(Voxel{glm::vec3(0.0, 0.0, 0.0), (glm::vec3(0.0, 1.0, 0.0))});

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

    /* Make the window's context current */
    glfwMakeContextCurrent(_window);
    /* User data (global) */
    glfwSetWindowUserPointer(_window, this);

    if (gladLoadGL(static_cast<GLADloadfunc>(glfwGetProcAddress)) == false) {
      std::cout << "GLAD LOAD ISSUE" << std::endl;
    }

    _shaderProgram = ShaderProgram(
        "C:\\Users\\fsanv\\my_projects\\voxel-engine\\core\\src\\VertexShader."
        "glsl",
        "C:\\Users\\fsanv\\my_projects\\voxel-"
        "engine\\core\\src\\FragmentShader.glsl");

    std::vector<glm::vec3> _voxels;
    for (int x = 0; x < 10; ++x)
      for (int y = 0; y < 5; ++y)
        for (int z = 0; z < 5; ++z) {
          _voxels.push_back(glm::vec3{static_cast<float>(-x * 2),
                                      static_cast<float>(y * 2),
                                      static_cast<float>(-z * 2)});
        }

    std::vector<glm::vec3> g_color_buffer_data;

    for (int i = 0; i < 250; ++i) {
      g_color_buffer_data.push_back(glm::vec3{
          (rand() % 10) * 0.1, (rand() % 10) * 0.1, (rand() % 10) * 0.1});
    }

    _model = VoxelModel{.voxels = _voxels, .colors = g_color_buffer_data};

    _renderer.Init();

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