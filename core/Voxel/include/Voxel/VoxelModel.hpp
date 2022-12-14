#pragma once

// clang-format off

#include <Voxel/Voxel.hpp>

#include <glm/glm.hpp>

#include <cstdint>
#include <vector>

// clang-format on

namespace VoxelEngine {

// TODO: модель как набор вокселей (поработать над передачей на отрисовку
// opengl)

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
