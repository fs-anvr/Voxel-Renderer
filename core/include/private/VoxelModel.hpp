#pragma once

#include <cstdint>
#include <vector>

#include <glm/glm.hpp>

namespace VoxelEngine {

struct VoxelModel {
  std::vector<glm::vec3> voxels;
  std::vector<glm::vec3> colors;
  glm::mat4 transform = glm::mat4(1.0);
};

}  // namespace VoxelEngine