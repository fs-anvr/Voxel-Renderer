#pragma once

#include <glad/gl.h>

#include <cstdint>
#include <glm/glm.hpp>
#include <vector>

namespace VoxelEngine {

template <typename T>
struct Vec3 {
  T x;
  T y;
  T z;
};

struct VoxelModel {
  std::vector<glm::vec3> voxels;
  std::vector<glm::vec3> colors;
  // MVP
};

}  // namespace VoxelEngine