#pragma once

#include <glad/gl.h>

#include <cstdint>

#include "VoxelModel.hpp"

namespace VoxelEngine {

class Renderer {
 public:
  Renderer();
  ~Renderer();

  static void Init();
  //TODO: static void Render(const Voxel&);
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