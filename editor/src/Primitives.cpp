#include <Voxel/Voxel.hpp>
#include <cstdint>
#include <vector>

class Primitives {
 public:
  static inline std::vector<VoxelEngine::Voxel> Cube3D(
      std::size_t size, glm::vec3 position = glm::vec3(0, 0, 0),
      glm::vec3 color = glm::vec3(1, 1, 1)) {
    return Rectangle3D(glm::vec3(size, size, size), position, color);
  }

  static inline std::vector<VoxelEngine::Voxel> Rectangle3D(
      glm::vec3 size, glm::vec3 position = glm::vec3(0, 0, 0),
      glm::vec3 color = glm::vec3(1, 1, 1)) {
    std::vector<VoxelEngine::Voxel> voxels(size.x * size.y * size.z);
    for (std::size_t x = 0; x < size.x; ++x) {
      for (std::size_t y = 0; y < size.y; ++y) {
        for (std::size_t z = 0; z < size.z; ++z) {
          voxels[x * size.y * size.z + y * size.z + z] = VoxelEngine::Voxel{
              .position = position + glm::vec3(x, y, z), .color = color};
        }
      }
    }

    return voxels;
  }

  static inline std::vector<VoxelEngine::Voxel> Sphere3D(
      std::int32_t radius, glm::vec3 position = glm::vec3(0, 0, 0),
      glm::vec3 color = glm::vec3(1, 1, 1)) {
    if (radius < 0) {
      return std::vector<VoxelEngine::Voxel>();
    }
    std::vector<VoxelEngine::Voxel> voxels;
    for (std::int32_t x = -radius; x <= radius; ++x) {
      for (std::int32_t y = -radius; y <= radius; ++y) {
        for (std::int32_t z = -radius; z <= radius; ++z) {
          if (x * x + y * y + z * z <= radius * radius) {
            voxels.push_back(VoxelEngine::Voxel{
                .position = position + glm::vec3(x, y, z), .color = color});
          }
        }
      }
    }

    return voxels;
  }

 private:
};