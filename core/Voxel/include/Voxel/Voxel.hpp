#pragma once

// clang-format off

#include <glm/glm.hpp>

#include <cstdint>
#include <vector>

// clang-format off

//TODO: abstract Voxel

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



/*class Voxel {
  using vec3 = glm::vec3;
  using mat4 = glm::mat4;

 public:
  Voxel() = default;
  
  virtual ~Voxel() = 0;

  virtual vec3 position() = 0;

  virtual vec3 color() = 0;
  
  virtual mat4 transform() = 0; 
};


class BasicVoxel : public Voxel {
  using vec3 = glm::vec3;
  using mat4 = glm::mat4;

 public:
  BasicVoxel(){}
  
  ~BasicVoxel() override {}

  vec3 position() override {}

  vec3 color() override {}

  mat4 transform() override{}
};
*/