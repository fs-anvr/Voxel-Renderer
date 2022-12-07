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

namespace VoxelEngine {

// TODO: вынести лишний код из Window

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

    constexpr double radius = 20.0;
    double CamX = sin(glfwGetTime()) * radius;
    double CamZ = cos(glfwGetTime()) * radius;
    glm::mat4 view;

    Camera camera;

    camera.Position = glm::vec3(CamX, 3.0, CamZ);
    camera.Target = glm::vec3(0.0, 0.0, 0.0);
    camera.Up = glm::vec3(0.0, 1.0, 0.0);

    // glm::mat4 MVP = projectionMaxtrix * viewMatrix * _model.transform;

    glm::mat4 MVP = camera.Projection() * camera.View() * _model.transform;

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

    return true;
  }

}  // namespace VoxelEngine