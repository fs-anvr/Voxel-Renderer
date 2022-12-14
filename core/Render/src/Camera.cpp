#include <Render/Camera.hpp>
#include <glm/glm.hpp>

namespace VoxelEngine {

// TODO: абстрагировать от углов эйлера

Camera::Camera()
    : position(glm::vec3(0.0f, 0.0f, 0.0f)), xAngle(0.0f), yAngle(0.0f) {}

Camera::Camera(glm::vec3 position, data_type xAngle, data_type yAngle,
               data_type fov, data_type aspect, data_type near, data_type far)
    : position(position),
      xAngle(xAngle),
      yAngle(yAngle),
      _fov(fov),
      _aspect(aspect),
      _near(near),
      _far(far) {}

Camera::Camera(float xPos, float yPos, float zPos, data_type xAngle,
               data_type yAngle, data_type fov, data_type aspect,
               data_type near, data_type far)
    : position(glm::vec3(xPos, yPos, zPos)),
      xAngle(xAngle),
      yAngle(yAngle),
      _fov(fov),
      _aspect(aspect),
      _near(near),
      _far(far) {}

Camera::~Camera() {}

void Camera::MoveInto(data_type x, data_type y, data_type z) {
  position = glm::vec3(x, y, z);
}

void Camera::MoveFor(data_type x, data_type y, data_type z) {
  position += x * Direction();
  position += y * Right();
  position += z * Up();
}

void Camera::RotateForAngle(data_type xAngle, data_type yAngle) {
  this->xAngle -= xAngle;
  this->yAngle -= yAngle;
}

glm::vec3 Camera::Direction() const {
  return glm::normalize(glm::vec3(cos(yAngle) * sin(xAngle), sin(yAngle),
                                  cos(yAngle) * cos(xAngle)));
}

glm::vec3 Camera::Right() const {
  return glm::normalize(
      glm::vec3(sin(xAngle - 3.14f / 2.0f), 0, cos(xAngle - 3.14f / 2.0f)));
}

glm::vec3 Camera::Up() const {
  return glm::normalize(glm::cross(Right(), Direction()));
}

glm::mat4 Camera::Projection() const {
  return glm::perspective(glm::radians(_fov), _aspect, _near, _far);
}

glm::mat4 Camera::View() const {
  return glm::lookAt(position, position + Direction(), Up());
}

}  // namespace VoxelEngine