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

  static inline std::vector<VoxelEngine::Voxel> Snowman() {
    using namespace VoxelEngine;
      std::vector<Voxel> snowman;

      //snowman.push_back(Voxel(glm::vec3(), glm::vec3()));

      //snowman.push_back(Voxel(glm::vec3(0, 0, 0), glm::vec3(1, 1, 1))); // white
      //snowman.push_back(Voxel(glm::vec3(1, 0, 0), glm::vec3(1, 1, 1))); // white
      //snowman.push_back(Voxel(glm::vec3(-1, 0, 0), glm::vec3(1, 1, 1))); // white
      //snowman.push_back(Voxel(glm::vec3(0, 0, -1), glm::vec3(1, 1, 1))); // white
      //snowman.push_back(Voxel(glm::vec3(0, 0, 1), glm::vec3(1, 1, 1))); // white
      //snowman.push_back(Voxel(glm::vec3(-1, 0, -1), glm::vec3(1, 1, 1))); // white
      //snowman.push_back(Voxel(glm::vec3(-1, 0, 1), glm::vec3(1, 1, 1))); // white
      //snowman.push_back(Voxel(glm::vec3(1, 0, -1), glm::vec3(1, 1, 1))); // white
      //snowman.push_back(Voxel(glm::vec3(1, 0, 1), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(-1, 0, -2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(0, 0, -2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(1, 0, -2), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(-1, 0, 2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(0, 0, 2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(1, 0, 2), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(-2, 0, -1), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(-2, 0, 0), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(-2, 0, 1), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(2, 0, -1), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(2, 0, 0), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(2, 0, 1), glm::vec3(1, 1, 1))); // white


      
      snowman.push_back(Voxel(glm::vec3(-1, 4, -2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(0, 4, -2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(1, 4, -2), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(-1, 4, 2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(0, 4, 2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(1, 4, 2), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(-2, 4, -1), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(-2, 4, 0), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(-2, 4, 1), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(2, 4, -1), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(2, 4, 0), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(2, 4, 1), glm::vec3(1, 1, 1))); // white

      
      
      snowman.push_back(Voxel(glm::vec3(-1, 1, -3), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(0, 1, -3), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(1, 1, -3), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(-1, 1, 3), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(0, 1, 3), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(1, 1, 3), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(-3, 1, -1), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(-3, 1, 0), glm::vec3(.15, .15, .15))); // grey
      snowman.push_back(Voxel(glm::vec3(-3, 1, 1), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(3, 1, -1), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(3, 1, 0), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(3, 1, 1), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(-2, 1, -2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(-2, 1, 2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(2, 1, -2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(2, 1, 2), glm::vec3(1, 1, 1))); // white

      
      
      snowman.push_back(Voxel(glm::vec3(-1, 2, -3), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(0, 2, -3), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(1, 2, -3), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(-1, 2, 3), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(0, 2, 3), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(1, 2, 3), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(-3, 2, -1), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(-3, 2, 0), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(-3, 2, 1), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(3, 2, -1), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(3, 2, 0), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(3, 2, 1), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(-2, 2, -2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(-2, 2, 2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(2, 2, -2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(2, 2, 2), glm::vec3(1, 1, 1))); // white

            
            
      snowman.push_back(Voxel(glm::vec3(-1, 3, -3), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(0, 3, -3), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(1, 3, -3), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(-1, 3, 3), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(0, 3, 3), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(1, 3, 3), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(-3, 3, -1), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(-3, 3, 0), glm::vec3(.15, .15, .15))); // grey
      snowman.push_back(Voxel(glm::vec3(-3, 3, 1), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(3, 3, -1), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(3, 3, 0), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(3, 3, 1), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(-2, 3, -2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(-2, 3, 2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(2, 3, -2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(2, 3, 2), glm::vec3(1, 1, 1))); // white



      snowman.push_back(Voxel(glm::vec3(0, 5, 0), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(1, 5, 0), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(-1, 5, 0), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(0, 5, -1), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(0, 5, 1), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(-1, 5, -1), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(-1, 5, 1), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(1, 5, -1), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(1, 5, 1), glm::vec3(1, 1, 1))); // white



      snowman.push_back(Voxel(glm::vec3(-1, 6, -2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(0, 6, -2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(1, 6, -2), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(-1, 6, 2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(0, 6, 2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(1, 6, 2), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(-2, 6, -1), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(-2, 6, 0), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(-2, 6, 1), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(2, 6, -1), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(2, 6, 0), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(2, 6, 1), glm::vec3(1, 1, 1))); // white



      snowman.push_back(Voxel(glm::vec3(-3, 6, 0), glm::vec3(1, .35, 0))); // orange



      snowman.push_back(Voxel(glm::vec3(-1, 7, -2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(0, 7, -2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(1, 7, -2), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(-1, 7, 2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(0, 7, 2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(1, 7, 2), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(-2, 7, -1), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(-2, 7, 0), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(-2, 7, 1), glm::vec3(0, 0, 0))); // black

      snowman.push_back(Voxel(glm::vec3(2, 7, -1), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(2, 7, 0), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(2, 7, 1), glm::vec3(1, 1, 1))); // white



      snowman.push_back(Voxel(glm::vec3(-1, 8, -2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(0, 8, -2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(1, 8, -2), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(-1, 8, 2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(0, 8, 2), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(1, 8, 2), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(-2, 8, -1), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(-2, 8, 0), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(-2, 8, 1), glm::vec3(1, 1, 1))); // white

      snowman.push_back(Voxel(glm::vec3(2, 8, -1), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(2, 8, 0), glm::vec3(1, 1, 1))); // white
      snowman.push_back(Voxel(glm::vec3(2, 8, 1), glm::vec3(1, 1, 1))); // white



      snowman.push_back(Voxel(glm::vec3(-1, 9, -3), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(0, 9, -3), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(1, 9, -3), glm::vec3(0, 0, 0))); // black

      snowman.push_back(Voxel(glm::vec3(-1, 9, 3), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(0, 9, 3), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(1, 9, 3), glm::vec3(0, 0, 0))); // black

      snowman.push_back(Voxel(glm::vec3(-3, 9, -1), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(-3, 9, 0), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(-3, 9, 1), glm::vec3(0, 0, 0))); // black

      snowman.push_back(Voxel(glm::vec3(3, 9, -1), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(3, 9, 0), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(3, 9, 1), glm::vec3(0, 0, 0))); // black

      snowman.push_back(Voxel(glm::vec3(-2, 9, -2), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(-2, 9, 2), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(2, 9, -2), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(2, 9, 2), glm::vec3(0, 0, 0))); // black



      snowman.push_back(Voxel(glm::vec3(-1, 10, -2), glm::vec3(1, 0, 0))); // red
      snowman.push_back(Voxel(glm::vec3(0, 10, -2), glm::vec3(1, 0, 0))); // red
      snowman.push_back(Voxel(glm::vec3(1, 10, -2), glm::vec3(1, 0, 0))); // red

      snowman.push_back(Voxel(glm::vec3(-1, 10, 2), glm::vec3(1, 0, 0))); // red
      snowman.push_back(Voxel(glm::vec3(0, 10, 2), glm::vec3(1, 0, 0))); // red
      snowman.push_back(Voxel(glm::vec3(1, 10, 2), glm::vec3(1, 0, 0))); // red

      snowman.push_back(Voxel(glm::vec3(-2, 10, -1), glm::vec3(1, 0, 0))); // red
      snowman.push_back(Voxel(glm::vec3(-2, 10, 0), glm::vec3(1, 0, 0))); // red
      snowman.push_back(Voxel(glm::vec3(-2, 10, 1), glm::vec3(1, 0, 0))); // red

      snowman.push_back(Voxel(glm::vec3(2, 10, -1), glm::vec3(1, 0, 0))); // red
      snowman.push_back(Voxel(glm::vec3(2, 10, 0), glm::vec3(1, 0, 0))); // red
      snowman.push_back(Voxel(glm::vec3(2, 10, 1), glm::vec3(1, 0, 0))); // red



      snowman.push_back(Voxel(glm::vec3(-1, 11, -2), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(0, 11, -2), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(1, 11, -2), glm::vec3(0, 0, 0))); // black

      snowman.push_back(Voxel(glm::vec3(-1, 11, 2), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(0, 11, 2), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(1, 11, 2), glm::vec3(0, 0, 0))); // black

      snowman.push_back(Voxel(glm::vec3(-2, 11, -1), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(-2, 11, 0), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(-2, 11, 1), glm::vec3(0, 0, 0))); // black

      snowman.push_back(Voxel(glm::vec3(2, 11, -1), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(2, 11, 0), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(2, 11, 1), glm::vec3(0, 0, 0))); // black



      snowman.push_back(Voxel(glm::vec3(-1, 12, -2), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(0, 12, -2), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(1, 12, -2), glm::vec3(0, 0, 0))); // black

      snowman.push_back(Voxel(glm::vec3(-1, 12, 2), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(0, 12, 2), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(1, 12, 2), glm::vec3(0, 0, 0))); // black

      snowman.push_back(Voxel(glm::vec3(-2, 12, -1), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(-2, 12, 0), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(-2, 12, 1), glm::vec3(0, 0, 0))); // black

      snowman.push_back(Voxel(glm::vec3(2, 12, -1), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(2, 12, 0), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(2, 12, 1), glm::vec3(0, 0, 0))); // black



      snowman.push_back(Voxel(glm::vec3(-1, 13, -2), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(0, 13, -2), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(1, 13, -2), glm::vec3(0, 0, 0))); // black

      snowman.push_back(Voxel(glm::vec3(-1, 13, 2), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(0, 13, 2), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(1, 13, 2), glm::vec3(0, 0, 0))); // black

      snowman.push_back(Voxel(glm::vec3(-2, 13, -1), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(-2, 13, 0), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(-2, 13, 1), glm::vec3(0, 0, 0))); // black

      snowman.push_back(Voxel(glm::vec3(2, 13, -1), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(2, 13, 0), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(2, 13, 1), glm::vec3(0, 0, 0))); // black



      snowman.push_back(Voxel(glm::vec3(0, 13, 0), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(1, 13, 0), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(-1, 13, 0), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(0, 13, -1), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(0, 13, 1), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(-1, 13, -1), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(-1, 13, 1), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(1, 13, -1), glm::vec3(0, 0, 0))); // black
      snowman.push_back(Voxel(glm::vec3(1, 13, 1), glm::vec3(0, 0, 0))); // black

      return snowman;
  }

 private:
};