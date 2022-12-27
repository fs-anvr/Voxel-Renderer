#pragma once

// clang-format off

#include <Render/Renderer.hpp>
#include <Shaders/ShaderProgram.hpp>

#include <cstdint>

// clang-format on

namespace VoxelEngine {

class OpenGLRenderer : public Renderer {
 public:
  OpenGLRenderer();
  ~OpenGLRenderer() override;

  void Init() override;
  void Rerender() override;

  ShaderProgram shaderProgram;

 private:
  std::uint32_t _voxelVertexBuffer;
  std::uint32_t _voxelIndexBuffer;
  std::uint32_t _colorBuffer;
  std::uint32_t _VBO;

  std::uint32_t _matrixBuffer;
};

}  // namespace VoxelEngine