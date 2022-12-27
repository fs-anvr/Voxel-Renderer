#pragma once

// clang-format off

#include <glm/glm.hpp>

#include <cstdint>
#include <vector>

// clang-format off

namespace VoxelEngine {

class Voxel {
 public:

  Voxel();

  Voxel(glm::vec3 position, glm::vec3 color, glm::mat4 transform = glm::mat4(1.0));

//FIXME: make virtual destructor
  ~Voxel() {}

  glm::vec3 position = glm::vec3(0.0);
  glm::vec3 color = glm::vec3(0.0);
  glm::mat4 transform = glm::mat4(1.0);

 private:
  //pass
};

}  // namespace VoxelEngine
