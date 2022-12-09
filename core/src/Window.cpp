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

namespace VoxelEngine {

// TODO: вынести лишний код из Window
// TODO: вынести камеру / клаву / мышь

float deltaTime = 0.0f;
float lastFrame = 0.0f;

float xAngleDelta = 0.0f;
float yAngleDelta = 0.0f;
bool firstMouseInput = true;

void ProcessInputKeyboard(GLFWwindow* window, Camera* camera) {
  const float speed = 5 * deltaTime;  // double doesn't work

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

void mouse_callback(GLFWwindow* window, double xPos, double yPos) {
  int wightWindow;
  int heightWindow;
  glfwGetWindowSize(window, &wightWindow, &heightWindow);

  float xCenter = wightWindow / 2.0f;
  float yCenter = heightWindow / 2.0f;

  if (firstMouseInput) {
    xCenter = xPos;
    yCenter = yPos;
    firstMouseInput = false;
  }

  const float kSpeedMouseRotate = 5000.0f;
  xAngleDelta = kSpeedMouseRotate * (xCenter - xPos) / wightWindow;
  yAngleDelta = kSpeedMouseRotate * (yCenter - yPos) / heightWindow;
}

void mouse_button_callback(GLFWwindow* window, int button, int action,
                           int mods) {
  if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
    // set mouse pos callback
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, mouse_callback);
  } else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE) {
    // remove mouse pos callback
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    glfwSetCursorPosCallback(
        window, [](GLFWwindow* window, double posX, double posY) {});
    xAngleDelta = 0.0f;
    yAngleDelta = 0.0f;
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

    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    ProcessInputKeyboard(this->_window, &_camera);

    float cameraSpeed = 0.0005f * deltaTime;

    _camera.xAngle += cameraSpeed * xAngleDelta;
    _camera.yAngle += cameraSpeed * yAngleDelta;

    glm::mat4 MVP = _camera.Projection() * _camera.View() * _model.transform;

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
    _camera.position = glm::vec3(-10.0, 5.0, 10.0);
    _camera.xAngle = 135.0;
    _camera.yAngle = 0.0;

    //glfwSetMouseButtonCallback(this->_window, mouse_button_callback);

    //glfwSetCursorPosCallback(_window, mouseMoveCallback);
    //glfwSetMouseButtonCallback(_window, mouseButtonCallback);

    return true;
  }

  void Window::setCallback(EventCallback callback) { _eventCallback = callback; }


  void Window::mouseMoveCallback(GLFWwindow* window, double x, double y) {
    auto& handle = *static_cast<Window*>(glfwGetWindowUserPointer(window));
    MouseMoveEvent event(x, y);
    handle._eventCallback(event);
  }

  void Window::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    auto& handle = *static_cast<Window*>(glfwGetWindowUserPointer(window));

    if (action == GLFW_PRESS) {
      MouseButtonPressEvent event(button, action, mods);
      handle._eventCallback(event);
    } else if (action == GLFW_RELEASE) {
      MouseButtonReleaseEvent event(button, action, mods);
      handle._eventCallback(event);
    }
  }

}  // namespace VoxelEngine