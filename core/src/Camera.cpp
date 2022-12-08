#include "private/Camera.hpp"

namespace VoxelEngine {

Camera::Camera() {}

Camera::~Camera() {}

glm::vec3 Camera::Direction() const {
  return glm::vec3(
    cos(yAngle) * sin(xAngle),
    sin(yAngle),
    cos(yAngle) * cos(xAngle)
  );
}

glm::vec3 Camera::Right() const {
  return glm::vec3(
    sin(xAngle - 3.14f/2.0f),
    0,
    cos(xAngle - 3.14f/2.0f)
  );
}

glm::vec3 Camera::Up() const {
  return glm::cross(Right(), Direction());
}

glm::mat4 Camera::Projection() const {
  return glm::perspective(glm::radians(_fov), _aspect, _near, _far);
}

glm::mat4 Camera::View() const {
  return glm::lookAt(position, position + Direction(), Up());
}

}  // namespace VoxelEngine