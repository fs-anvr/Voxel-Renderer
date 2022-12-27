#include <Voxel/Voxel.hpp>

// clang-format off

#include <glm/glm.hpp>

#include <cstdint>
#include <vector>

// clang-format off

namespace VoxelEngine {

Voxel::Voxel()
  : position(glm::vec3(0.0)), color(glm::vec3(0.0)), transform(glm::mat4(1.0)) {}

Voxel::Voxel(glm::vec3 position, glm::vec3 color, glm::mat4 transform)
  : position(position), color(color), transform(transform) {}

}  // namespace VoxelEngine
