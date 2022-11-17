#pragma once

#include <vector>
#include <cstdint>

#include <glad/gl.h>
#include <glm/glm.hpp>

namespace VoxelEngine {

  template<typename T>
  struct Vec3 {
    T x;
    T y;
    T z;
  };

  struct VoxelModel {
    std::vector< glm::vec3 > voxels;
    std::vector< glm::vec3 > colors;
    //MVP
  };

}  // namespace VoxelEngine