#pragma once

#include "private/VoxelModel.hpp"
#include "private/Voxel.hpp"

#include <glad/gl.h>

#include <cstdint>

namespace VoxelEngine {

class Renderer {
 public:
  Renderer();
  ~Renderer();

  static void Init();
  static void Render(const Voxel&);
  static void Render(const VoxelModel&);

 private:
  static GLuint _voxelVertexBuffer;
  static GLuint _voxelIndexBuffer;
  static GLuint _colorBuffer;
  static GLuint _VBO;

  static const std::int32_t _voxelVertexSize;
  static const GLfloat _voxelVertex[];
  static const GLint _voxelIndex[];
};

}  // namespace VoxelEngine