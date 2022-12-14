// clang-format off
#include <Render/Renderer.hpp>

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

// clang-format on

namespace VoxelEngine {

GLuint Renderer::_voxelVertexBuffer;
GLuint Renderer::_voxelIndexBuffer;
GLuint Renderer::_colorBuffer;
GLuint Renderer::_VBO;

const std::int32_t Renderer::_voxelVertexSize = 36;

// clang-format off

const GLfloat Renderer::_voxelVertex[] = {
  0.0f, 0.0f, 1.0f,
  0.0f, 1.0f, 1.0f,
  1.0f, 1.0f, 1.0f,
  1.0f, 0.0f, 1.0f,
  0.0f, 0.0f, 0.0f,
  0.0f, 1.0f, 0.0f,
  1.0f, 1.0f, 0.0f,
  1.0f, 0.0f, 0.0f
};

const GLint Renderer::_voxelIndex[] = {
  // front
  0, 3, 1, 2, 1, 3,
  // back
  4, 5, 7, 6, 7, 5,
  // right
  3, 7, 2, 6, 2, 7,
  // left
  0, 1, 4, 5, 4, 1,
  // top
  2, 6, 1, 5, 1, 6,
  // bottom
  3, 0, 7, 4, 7, 0
};

// clang-format on

Renderer::Renderer() {}

Renderer::~Renderer() {}

void Renderer::Init() {
  glGenBuffers(1, &_voxelVertexBuffer);
  glGenBuffers(1, &_voxelIndexBuffer);
  glGenBuffers(1, &_colorBuffer);
  glGenBuffers(1, &_VBO);

  glBindBuffer(GL_ARRAY_BUFFER, _voxelVertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(_voxelVertex), &_voxelVertex,
               GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _voxelIndexBuffer);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_voxelIndex), &_voxelIndex,
               GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(0));

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glEnable(GL_CULL_FACE);
}

void Renderer::Render(const VoxelModel& model) {
  glBindBuffer(GL_ARRAY_BUFFER, _colorBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(model.colors[0]) * model.colors.size(),
               &model.colors[0], GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER, _VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(model.voxels[0]) * model.voxels.size(),
               &model.voxels[0], GL_STATIC_DRAW);

  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, _colorBuffer);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(0));
  glVertexAttribDivisor(1, 1);

  glEnableVertexAttribArray(2);
  glBindBuffer(GL_ARRAY_BUFFER, _VBO);
  glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(0));
  glVertexAttribDivisor(2, 1);

  glDrawElementsInstanced(GL_TRIANGLES, _voxelVertexSize, GL_UNSIGNED_INT,
                          static_cast<void*>(0), model.voxels.size());
}

void Renderer::Render(const Voxel& voxel) {
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

}  // namespace VoxelEngine