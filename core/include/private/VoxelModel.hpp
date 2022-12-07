#pragma once

#include "private/Voxel.hpp"

#include <cstdint>
#include <vector>

#include <glm/glm.hpp>

namespace VoxelEngine {

// TODO: модель как набор вокселей (поработать над передачей на отрисовку opengl)

struct VoxelModel {
  std::vector<glm::vec3> voxels;
  std::vector<glm::vec3> colors;
  glm::mat4 transform = glm::mat4(1.0);
};

/*struct VoxelModel {
  std::vector<Voxel> voxels;
};*/

/*struct VoxelModel {
  std::vector<BaseVoxel> voxels;
  glm::mat4 transform = glm::mat4(1.0);
}*/

}  // namespace VoxelEngine
