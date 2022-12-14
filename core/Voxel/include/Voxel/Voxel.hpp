#pragma once

// clang-format off

#include <glm/glm.hpp>

#include <cstdint>
#include <vector>

// clang-format off

namespace VoxelEngine {

struct Voxel {
  glm::vec3 position;
  glm::vec3 color;
  glm::mat4 transform = glm::mat4(1.0);
};

/*struct BaseVoxel {
  glm::vec3 position;
  glm::vec3 color;
};*/

}  // namespace VoxelEngine
