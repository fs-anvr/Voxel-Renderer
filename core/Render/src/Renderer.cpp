// clang-format off

#include <Render/Renderer.hpp>

// clang-format on

namespace VoxelEngine {

const std::int32_t Renderer::_voxelVertexSize = 36;

const std::int32_t Renderer::_voxelIndexSize = 24;

const std::int32_t Renderer::_voxelNormalSize = 108;

// clang-format off

const float Renderer::_voxelVertex[] = {
  0.0f, 0.0f, 1.0f,
  0.0f, 1.0f, 1.0f,
  1.0f, 1.0f, 1.0f,
  1.0f, 0.0f, 1.0f,
  0.0f, 0.0f, 0.0f,
  0.0f, 1.0f, 0.0f,
  1.0f, 1.0f, 0.0f,
  1.0f, 0.0f, 0.0f
};

const int Renderer::_voxelIndex[] = {
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

const float Renderer::_voxelNormal[] = {
  //front
  0.0f, 0.0f, 1.0f,
  0.0f, 0.0f, 1.0f,
  0.0f, 0.0f, 1.0f,
  0.0f, 0.0f, 1.0f,
  0.0f, 0.0f, 1.0f,
  0.0f, 0.0f, 1.0f,
  //back
  0.0f, 0.0f, -1.0f,
  0.0f, 0.0f, -1.0f,
  0.0f, 0.0f, -1.0f,
  0.0f, 0.0f, -1.0f,
  0.0f, 0.0f, -1.0f,
  0.0f, 0.0f, -1.0f,
  //right
  1.0f, 0.0f, 0.0f,
  1.0f, 0.0f, 0.0f,
  1.0f, 0.0f, 0.0f,
  1.0f, 0.0f, 0.0f,
  1.0f, 0.0f, 0.0f,
  1.0f, 0.0f, 0.0f,
  //left
  -1.0f, 0.0f, 0.0f,
  -1.0f, 0.0f, 0.0f,
  -1.0f, 0.0f, 0.0f,
  -1.0f, 0.0f, 0.0f,
  -1.0f, 0.0f, 0.0f,
  -1.0f, 0.0f, 0.0f,
  //top
  0.0f, 1.0f, 0.0f,
  0.0f, 1.0f, 0.0f,
  0.0f, 1.0f, 0.0f,
  0.0f, 1.0f, 0.0f,
  0.0f, 1.0f, 0.0f,
  0.0f, 1.0f, 0.0f,
  //bottom
  0.0f, -1.0f, 0.0f,
  0.0f, -1.0f, 0.0f,
  0.0f, -1.0f, 0.0f,
  0.0f, -1.0f, 0.0f,
  0.0f, -1.0f, 0.0f,
  0.0f, -1.0f, 0.0f
};

// clang-format on

}  // namespace VoxelEngine