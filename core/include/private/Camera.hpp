#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace VoxelEngine {

class Camera {
 public:
  glm::vec3 Position;
  glm::vec3 Target;
  glm::vec3 Up;

  Camera();

  ~Camera();

  // TODO: сделать разные виды камер (не только перспективу)
  //  enum и вид камеры ИЛИ разные методы?

  glm::mat4 Projection() const;  // perspective

  glm::mat4 View() const;

 private:
  // glm::vec3 _direction;
  // glm::vec3 _right;

  double _fov = 60.0;
  double _aspect = 16.0 / 9.0;
  double _near = 0.01;
  double _far = 90.0;
};

}  // namespace VoxelEngine