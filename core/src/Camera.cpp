#include "private/Camera.hpp"

namespace VoxelEngine {

Camera::Camera() {}

Camera::~Camera() {}

glm::mat4 Camera::Projection() const {
  return glm::perspective(glm::radians(_fov), _aspect, _near, _far);
}

glm::mat4 Camera::View() const { return glm::lookAt(Position, Target, Up); }

}  // namespace VoxelEngine