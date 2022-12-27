#include <Voxel/Voxel.hpp>
#include <cmath>
#include <cstdint>
#include <vector>

class Primitives {
 public:
  static inline std::vector<VoxelEngine::Voxel> Cube3D(
      std::size_t size, glm::vec3 position = glm::vec3(0, 0, 0),
      glm::vec3 color = glm::vec3(1, 1, 1)) {
    return Rectangle3D(glm::vec3(size, size, size), position, color);
  }

  static inline std::vector<VoxelEngine::Voxel> Cube3DRandomColor(
      std::size_t size, glm::vec3 position = glm::vec3(0, 0, 0)) {
    return Rectangle3DRandomColor(glm::vec3(size, size, size), position);
  }

  static inline std::vector<VoxelEngine::Voxel> Rectangle3D(
      glm::vec3 size, glm::vec3 position = glm::vec3(0, 0, 0),
      glm::vec3 color = glm::vec3(1, 1, 1)) {
    size = glm::vec3(static_cast<std::int32_t>(size.x),
                     static_cast<std::int32_t>(size.y),
                     static_cast<std::int32_t>(size.z));
    std::vector<VoxelEngine::Voxel> voxels(size.x * size.y * size.z);
    for (std::size_t x = 0; x < static_cast<std::size_t>(size.x); ++x) {
      for (std::size_t y = 0; y < static_cast<std::size_t>(size.y); ++y) {
        for (std::size_t z = 0; z < static_cast<std::size_t>(size.z); ++z) {
          voxels[x * static_cast<std::size_t>(size.y) *
                     static_cast<std::size_t>(size.z) +
                 y * static_cast<std::size_t>(size.z) + z] = VoxelEngine::Voxel(
              glm::vec3(static_cast<std::int32_t>(round(position.x)),
                            static_cast<std::int32_t>(round(position.y)),
                            static_cast<std::int32_t>(round(position.z))) +
                  glm::vec3(x, y, z),
              color);
        }
      }
    }

    return voxels;
  }

    static inline std::vector<VoxelEngine::Voxel> Rectangle3DRandomColor(
      glm::vec3 size, glm::vec3 position = glm::vec3(0, 0, 0)) {
    size = glm::vec3(static_cast<std::int32_t>(size.x),
                     static_cast<std::int32_t>(size.y),
                     static_cast<std::int32_t>(size.z));
    std::vector<VoxelEngine::Voxel> voxels(size.x * size.y * size.z);
    for (std::size_t x = 0; x < static_cast<std::size_t>(size.x); ++x) {
      for (std::size_t y = 0; y < static_cast<std::size_t>(size.y); ++y) {
        for (std::size_t z = 0; z < static_cast<std::size_t>(size.z); ++z) {
          voxels[x * static_cast<std::size_t>(size.y) *
                     static_cast<std::size_t>(size.z) +
                 y * static_cast<std::size_t>(size.z) + z] = VoxelEngine::Voxel(
              glm::vec3(static_cast<std::int32_t>(round(position.x)),
                            static_cast<std::int32_t>(round(position.y)),
                            static_cast<std::int32_t>(round(position.z))) +
                  glm::vec3(x, y, z),
              glm::vec3((rand() % 10) * 0.1, (rand() % 10) * 0.1,
                                   (rand() % 10) * 0.1));
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
            voxels.push_back(VoxelEngine::Voxel(
                glm::vec3(static_cast<std::int32_t>(position.x),
                                      static_cast<std::int32_t>(position.y),
                                      static_cast<std::int32_t>(position.z)) +
                            glm::vec3(x, y, z),
                color));
          }
        }
      }
    }

    return voxels;
  }

  static inline std::vector<VoxelEngine::Voxel> Sphere3DRandomColor(
      std::int32_t radius, glm::vec3 position = glm::vec3(0, 0, 0)) {
    if (radius < 0) {
      return std::vector<VoxelEngine::Voxel>();
    }
    std::vector<VoxelEngine::Voxel> voxels;
    for (std::int32_t x = -radius; x <= radius; ++x) {
      for (std::int32_t y = -radius; y <= radius; ++y) {
        for (std::int32_t z = -radius; z <= radius; ++z) {
          if (x * x + y * y + z * z <= radius * radius) {
            voxels.push_back(VoxelEngine::Voxel(
                glm::vec3(static_cast<std::int32_t>(position.x),
                                      static_cast<std::int32_t>(position.y),
                                      static_cast<std::int32_t>(position.z)) +
                            glm::vec3(x, y, z),
                glm::vec3((rand() % 10) * 0.1, (rand() % 10) * 0.1,
                                   (rand() % 10) * 0.1)));
          }
        }
      }
    }

    return voxels;
  }

 private:
};