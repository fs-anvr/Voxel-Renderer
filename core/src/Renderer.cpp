#include "private/Renderer.hpp"

#include <GLFW/glfw3.h>
#include <glad/gl.h>

#include <glm/glm.hpp>

namespace VoxelEngine {

GLuint Renderer::voxelVertexBuffer;
GLuint Renderer::voxelIndexBuffer;
GLuint Renderer::colorBuffer;
GLuint Renderer::VBO;

Renderer::Renderer() {}

Renderer::~Renderer() {}

void Renderer::Init() {
  glGenBuffers(1, &voxelVertexBuffer);
  glGenBuffers(1, &voxelIndexBuffer);
  glGenBuffers(1, &colorBuffer);
  glGenBuffers(1, &VBO);

  glBindBuffer(GL_ARRAY_BUFFER, voxelVertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(voxelVertex), &voxelVertex,
               GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, voxelIndexBuffer);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(voxelIndex), &voxelIndex,
               GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(0));

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glEnable(GL_CULL_FACE);
}

void Renderer::Render(const VoxelModel& model) {
  glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(model.colors[0]) * model.colors.size(),
               &model.colors[0], GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(model.voxels[0]) * model.voxels.size(),
               &model.voxels[0], GL_STATIC_DRAW);

  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(0));
  glVertexAttribDivisor(1, 1);

  glEnableVertexAttribArray(2);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(0));
  glVertexAttribDivisor(2, 1);
  
  glDrawElementsInstanced(GL_TRIANGLES, VOXEL_VERTEX_NUM, GL_UNSIGNED_INT,
                          static_cast<void*>(0), model.voxels.size());
}
}  // namespace VoxelEngine