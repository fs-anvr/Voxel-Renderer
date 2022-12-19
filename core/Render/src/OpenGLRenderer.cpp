// clang-format off

#include <Render/OpenGLRenderer.hpp>
#include <Render/Renderables.hpp>
#include <ServiceLocator/ServiceLocator.hpp>

#include <glad/gl.h>
#include <glm/glm.hpp>

// clang-format on

namespace VoxelEngine {

OpenGLRenderer::OpenGLRenderer() { this->Init(); }

OpenGLRenderer::~OpenGLRenderer() {}

void OpenGLRenderer::Init() {
  shaderProgram = ShaderProgram(
      "C:\\Users\\fsanv\\my_projects\\voxel-"
      "engine\\core\\Shaders\\include\\Shaders\\VertexShader.glsl",
      "C:\\Users\\fsanv\\my_projects\\voxel-"
      "engine\\core\\Shaders\\include\\Shaders\\FragmentShader.glsl");

  glUseProgram(shaderProgram.id);

  glGenBuffers(1, &_voxelVertexBuffer);
  glGenBuffers(1, &_voxelIndexBuffer);
  glGenBuffers(1, &_colorBuffer);
  glGenBuffers(1, &_VBO);

  glBindBuffer(GL_ARRAY_BUFFER, _voxelVertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * Renderer::_voxelIndexSize,
               &_voxelVertex, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _voxelIndexBuffer);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,
               sizeof(int) * Renderer::_voxelVertexSize, &_voxelIndex,
               GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(0));

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glEnable(GL_CULL_FACE);
}

void OpenGLRenderer::Rerender() {
  /* clear */
  glClearColor(0.1, 0.1, 0.1, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  Camera& camera = ServiceLocator::Camera();

  const glm::mat4 MV = camera.Projection() * camera.View();

  for (auto voxel : ServiceLocator::Scene().GetVoxels()) {
    const glm::mat4 MVP = MV * voxel.transform;

    GLuint MatrixID = glGetUniformLocation(shaderProgram.id, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

    glBindBuffer(GL_ARRAY_BUFFER, _colorBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(voxel.color), &voxel.color,
                 GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(voxel.position), &voxel.position,
                 GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, _colorBuffer);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(0));
    glVertexAttribDivisor(1, 1);

    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(0));
    glVertexAttribDivisor(2, 1);

    glDrawElements(GL_TRIANGLES, _voxelVertexSize, GL_UNSIGNED_INT,
                   static_cast<void*>(0));
  }
}

}  // namespace VoxelEngine