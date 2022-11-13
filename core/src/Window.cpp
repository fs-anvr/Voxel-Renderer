#include <iostream>
#include <cstdint>
#include <string>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
//#include <glm/gtx/projection.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Window.hpp"
#include "ShaderLoader.hpp"

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

    /*static glm::mat4 projectionMaxtrix = glm::ortho(
      -1.0, 1.0, -1.0, 1.0,
      0.1,
      90.0
    );*/

    static glm::mat4 viewMatrix = glm::lookAt(
      glm::vec3(3, 3, 3), // camera position
      glm::vec3(0, 0, 0), // look at
      glm::vec3(0, 1, 0) // top
    );

    static glm::mat4 modelMatrix = glm::mat4(1.0);

    glm::mat4 MVP = projectionMaxtrix * viewMatrix * modelMatrix;

    static GLuint MatrixID = glGetUniformLocation(_shaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

    glUseProgram(_shaderProgram);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
    glVertexAttribPointer(
      0,                  // атрибут 0
      3,                  // размер
      GL_FLOAT,           // тип
      GL_FALSE,           // значения не нормализованы
      0,                  // шаг
      (void*)0            // смещение массива в буфере
    );

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, _colorBuffer);
    glVertexAttribPointer(
      1,                  // атрибут 1
      3,                  // размер
      GL_FLOAT,           // тип
      GL_FALSE,           // значения не нормализованы
      0,                  // шаг
      (void*)0            // смещение массива в буфере
    );

    /* draw */
    glDrawArrays(GL_TRIANGLES, 0, 12 * 3);

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
      "C:\\Users\\fsanv\\my_projects\\voxel-engine\\core\\src\\VertexShader.glsl",
      "C:\\Users\\fsanv\\my_projects\\voxel-engine\\core\\src\\FragmentShader.glsl");


    static const GLfloat g_vertex_buffer_data[] = {

      // front
      -1.0f, -1.0f, 1.0f,
      -1.0f, 1.0f, 1.0f,
      1.0f, -1.0f, 1.0f,

      1.0f, -1.0f, 1.0f,
      -1.0f, 1.0f, 1.0f,
      1.0f, 1.0f, 1.0f,

      // back
      -1.0f, -1.0f, -1.0f,
      -1.0f, 1.0f, -1.0f,
      1.0f, -1.0f, -1.0f,

      1.0f, -1.0f, -1.0f,
      -1.0f, 1.0f, -1.0f,
      1.0f, 1.0f, -1.0f,
      
      // right
      1.0f, -1.0f, -1.0f,
      1.0f, -1.0f, 1.0f,
      1.0f, 1.0f, 1.0f,

      1.0f, -1.0f, -1.0f,
      1.0f, 1.0f, 1.0f,
      1.0f, 1.0f, -1.0f,

      // left
      -1.0f, -1.0f, -1.0f,
      -1.0f, -1.0f, 1.0f,
      -1.0f, 1.0f, 1.0f,

      -1.0f, -1.0f, -1.0f,
      -1.0f, 1.0f, 1.0f,
      -1.0f, 1.0f, -1.0f,

      // top
      1.0f, 1.0f, 1.0f,
      -1.0f, 1.0f, 1.0f,
      -1.0f, 1.0f, -1.0f,

      1.0f, 1.0f, 1.0f,
      -1.0f, 1.0f, -1.0f,
      1.0f, 1.0f, -1.0f,

      // bottom
      1.0f, -1.0f, 1.0f,
      -1.0f, -1.0f, 1.0f,
      -1.0f, -1.0f, -1.0f,

      1.0f, -1.0f, 1.0f,
      -1.0f, -1.0f, -1.0f,
      1.0f, -1.0f, -1.0f
    };

    static const GLfloat g_color_buffer_data[] = {
      0.583f,  0.771f,  0.014f,
      0.609f,  0.115f,  0.436f,
      0.327f,  0.483f,  0.844f,
      0.822f,  0.569f,  0.201f,
      0.435f,  0.602f,  0.223f,
      0.310f,  0.747f,  0.185f,
      0.597f,  0.770f,  0.761f,
      0.559f,  0.436f,  0.730f,
      0.359f,  0.583f,  0.152f,
      0.483f,  0.596f,  0.789f,
      0.559f,  0.861f,  0.639f,
      0.195f,  0.548f,  0.859f,
      0.014f,  0.184f,  0.576f,
      0.771f,  0.328f,  0.970f,
      0.406f,  0.615f,  0.116f,
      0.676f,  0.977f,  0.133f,
      0.971f,  0.572f,  0.833f,
      0.140f,  0.616f,  0.489f,
      0.997f,  0.513f,  0.064f,
      0.945f,  0.719f,  0.592f,
      0.543f,  0.021f,  0.978f,
      0.279f,  0.317f,  0.505f,
      0.167f,  0.620f,  0.077f,
      0.347f,  0.857f,  0.137f,
      0.055f,  0.953f,  0.042f,
      0.714f,  0.505f,  0.345f,
      0.783f,  0.290f,  0.734f,
      0.722f,  0.645f,  0.174f,
      0.302f,  0.455f,  0.848f,
      0.225f,  0.587f,  0.040f,
      0.517f,  0.713f,  0.338f,
      0.053f,  0.959f,  0.120f,
      0.393f,  0.621f,  0.362f,
      0.673f,  0.211f,  0.457f,
      0.820f,  0.883f,  0.371f,
      0.982f,  0.099f,  0.879f
    };



    _vertexBuffer;
    glGenBuffers(1, &_vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    _colorBuffer;
    glGenBuffers(1, &_colorBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, _colorBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    return true;
  }

}  // namespace VoxelEngine