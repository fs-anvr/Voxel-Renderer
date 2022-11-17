#include <iostream>
#include <cstdint>
#include <string>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "private/Window.hpp"
#include "private/ShaderLoader.hpp"
#include "private/VoxelModel.hpp"
#include "private/Renderer.hpp"

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
    /* clear */
    
    glClearColor(0.1, 0.1, 0.1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    static double FoV = 90;
    static double aspectRatio = 16 / 9;

    static glm::mat4 projectionMaxtrix = glm::perspective (
      glm::radians(FoV),
      aspectRatio,
      0.1,
      90.0
    );

    static glm::mat4 viewMatrix =
        glm::lookAt(glm::vec3(10, 10, 5),  // camera position
                    glm::vec3(0, 5, 0),    // look at
                    glm::vec3(0, 1, 0)     // top
        );

    static glm::mat4 modelMatrix = glm::mat4(1.0);

    glm::mat4 MVP = projectionMaxtrix * viewMatrix * modelMatrix;

    static GLuint MatrixID = glGetUniformLocation(_shaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

    glUseProgram(_shaderProgram);


    _renderer.Render(_model);

    
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

    _shaderProgram = ShaderLoader::LoadShaders(
        "C:\\Users\\fsanv\\my_projects\\voxel-engine\\core\\src\\VertexShader."
        "glsl",
        "C:\\Users\\fsanv\\my_projects\\voxel-"
        "engine\\core\\src\\FragmentShader.glsl");

    static const GLfloat g_vertex_buffer_data[] = {
        0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,

        0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f};

    static const GLuint g_index_buffer_data[] = {// front
                                                 0, 3, 1, 2, 1, 3,

                                                 // back
                                                 4, 7, 5, 6, 5, 7,

                                                 // right
                                                 3, 7, 2, 6, 2, 7,

                                                 // left
                                                 0, 4, 1, 5, 1, 4,

                                                 // top
                                                 2, 6, 1, 5, 1, 6,

                                                 // bottom
                                                 3, 7, 0, 4, 0, 7};
    
    std::vector<glm::vec3> _voxels;
    for (int x = 0; x < 10; ++x)
      for (int y = 0; y < 5; ++y)
        for (int z = 0; z < 5; ++z) {
          _voxels.push_back(glm::vec3{
            static_cast<float>(-x * 2),
            static_cast<float>(y * 2),
            static_cast<float>(-z * 2)
          });
        }

    std::vector<glm::vec3> g_color_buffer_data;
    //g_color_buffer_data.reserve(250);

    for (int i = 0; i < 250; ++i) {
      g_color_buffer_data.push_back(glm::vec3{
        (rand() % 10) * 0.1,
        (rand() % 10) * 0.1,
        (rand() % 10) * 0.1
      });
    }


    _model = VoxelModel{
      .voxels = _voxels,
      .colors = g_color_buffer_data
    };

    std::cout << _model.voxels.size();

    _renderer = Renderer();
    _renderer.Init();

    return true;
  }

}  // namespace VoxelEngine