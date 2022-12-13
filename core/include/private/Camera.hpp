#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace VoxelEngine {

class Camera {
 public:
  using data_type = float;

  Camera();

  Camera(glm::vec3 pos, data_type xAngle, data_type yAngle, data_type fov = 60.0,
      data_type aspect = 16.0 / 9.0, data_type near = 0.01,
      data_type far = 90.0);

  Camera(float xPos, float yPos, float zPos,
    data_type xAngle, data_type yAngle,
    data_type fov = 60.0, data_type aspect = 16.0 / 9.0,
    data_type near = 0.01, data_type far = 90.0);

  ~Camera();

  //TODO: RotateForAngle(90) methods

  //TODO: абстракция своих векторов над glm::vec3

  void MoveInto(data_type x, data_type y, data_type z);

  void MoveFor(data_type x, data_type y, data_type z);

  void RotateForAngle(data_type xAngle, data_type yAngle);

  glm::vec3 Direction() const;

  glm::vec3 Right() const;

  glm::vec3 Up() const;

  // TODO: сделать разные виды камер (не только перспективу)
  //  enum и вид камеры ИЛИ разные методы?

  glm::mat4 Projection() const;  // perspective

  glm::mat4 View() const;

  glm::vec3 position;
  float xAngle;
  float yAngle;

 private:
  data_type _fov = 60.0;
  data_type _aspect = 16.0 / 9.0;
  data_type _near = 0.01;
  data_type _far = 90.0;
};

}  // namespace VoxelEngine