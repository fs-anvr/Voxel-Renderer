#pragma once

// clang-format off

#include <cstdint>

// clang-format on

namespace VoxelEngine {

class Renderer {
 public:
  Renderer() = default;
  virtual ~Renderer() = default;

  virtual void Init() = 0;

  virtual void Rerender() = 0;

 protected:
  static const std::int32_t _voxelVertexSize;
  static const std::int32_t _voxelIndexSize;
  static const float _voxelVertex[];
  static const int _voxelIndex[];
};

}  // namespace VoxelEngine