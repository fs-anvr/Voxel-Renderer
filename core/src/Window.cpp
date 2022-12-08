#include "private/Window.hpp"

#include "private/ShaderProgram.hpp"
#include "private/VoxelModel.hpp"
#include "private/Renderer.hpp"
#include "private/Camera.hpp"

#include <GLFW/glfw3.h>
#include <glad/gl.h>

#include <cstdint>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <string>

namespace VoxelEngine {

// TODO: вынести лишний код из Window

float deltaTime = 0.0f;
float lastFrame = 0.0f;

float xAngleDelta = 0.0f;
float yAngleDelta = 0.0f;
bool firstMouseInput = true;

void ProcessInputKeyboard(GLFWwindow* window, Camera* camera) {
  int count = 0;
  const float speed = 5 * deltaTime; // double doesn't work

  if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
    camera->position += speed * camera->Direction();
    ++count;
    std::cout << 'W' << std::endl;
  }
  if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
    camera->position -= speed * camera->Direction();
    ++count;
    std::cout << 'S' << std::endl;
  }
  if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
    camera->position += speed * glm::normalize(camera->Right());
    ++count;
    std::cout << 'D' << std::endl;
  }
  if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
    camera->position -= speed * glm::normalize(camera->Right());
    ++count;
    std::cout << 'A' << std::endl;
  }
}

void mouse_callback(GLFWwindow* window, double posX, double posY) {
  int windowWidth;
  int windowHeight;
  glfwGetWindowSize(window, &windowWidth, &windowHeight);
  
  float lastX = windowWidth / 2.0f;
  float lastY = windowHeight / 2.0f;

  if (firstMouseInput) {
    lastX = posX;
    lastY = posY;
    firstMouseInput = false;
  }

  xAngleDelta = lastX - posX;
  yAngleDelta = lastY - posY;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
  if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
    //set mouse pos callback
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, mouse_callback);
  }
  else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE) {
    //remove mouse pos callback
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    glfwSetCursorPosCallback(window, [](GLFWwindow* window, double posX, double posY){});
    xAngleDelta = 0.0f;
    yAngleDelta = 0.0f;
  }
}

void ProcessInputMouse(GLFWwindow* window) {
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  glfwSetCursorPosCallback(window, mouse_callback);
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



    static double FoV = 90;
    static double aspectRatio = 16.0f / 9.0f;

    static glm::mat4 projectionMaxtrix = glm::perspective (
      glm::radians(FoV),
      aspectRatio,
      0.1,
      90.0
    );

    static glm::mat4 viewMatrix =
        glm::lookAt(glm::vec3(10, 10, 5),  // camera position
                    glm::vec3(0, 5, 0),    // target
                    glm::vec3(0, 1, 0)     // up
        );
    
    // glm::mat4 MVP = projectionMaxtrix * viewMatrix * _model.transform;

    //constexpr double radius = 20.0;
    //double CamX = sin(glfwGetTime()) * radius;
    //double CamZ = cos(glfwGetTime()) * radius;

    //_camera.Position = glm::vec3(CamX, 3.0, CamZ);
    //_camera.Target = glm::vec3(0.0, 0.0, 0.0);
    //_camera.Up = glm::vec3(0.0, 1.0, 0.0);


    ProcessInputKeyboard(this->_window, &_camera);
    //ProcessInputMouse(this->_window);

    /*glm::vec3 direction = glm::vec3 (
      cos(glm::radians(yaw)) * cos(glm::radians(pitch)),
      sin(glm::radians(pitch)),
      sin(glm::radians(yaw)) * cos(glm::radians(pitch))
    );
    _camera.Direction = glm::normalize(direction);*/

    glfwSetMouseButtonCallback(this->_window, mouse_button_callback);

    float cameraSpeed = 0.0005f * deltaTime;

    _camera.xAngle += cameraSpeed * xAngleDelta;
    _camera.yAngle += cameraSpeed * yAngleDelta;


    glm::mat4 MVP = _camera.Projection() * _camera.View() * _model.transform;

    static GLuint MatrixID = glGetUniformLocation(_shaderProgram.id, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

    glUseProgram(_shaderProgram.id);

    _renderer.Render(_model);
    //_renderer.Render(Voxel{glm::vec3(0.0, 0.0, 0.0), (glm::vec3(0.0, 1.0,
    //0.0))});

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
    _camera.xAngle = 135.0f;
    _camera.yAngle = 0.0f;
    //_camera.Direction = glm::vec3(0.0, -0.2, -1.0);
    //_camera.Up = glm::vec3(0.0, 1.0, 0.0);

    return true;
  }

}  // namespace VoxelEngine