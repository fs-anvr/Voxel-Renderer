#pragma once

// clang-format off

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// clang-format on

//TODO: abstract Camera

namespace VoxelEngine {

class Camera {
 public:
  using data_type = float;

  Camera();

  Camera(glm::vec3 pos, data_type xAngle, data_type yAngle,
         data_type fov = 60.0, data_type aspect = 16.0 / 9.0,
         data_type near = 0.01, data_type far = 90.0);

  Camera(float xPos, float yPos, float zPos, data_type xAngle, data_type yAngle,
         data_type fov = 60.0, data_type aspect = 16.0 / 9.0,
         data_type near = 0.01, data_type far = 90.0);

  ~Camera();

  // TODO: абстракция своих векторов над glm::vec3

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
  data_type xAngle;
  data_type yAngle;

 private:
  data_type _fov = 60.0f;
  data_type _aspect = 16.0f / 9.0f;
  data_type _near = 0.01f;
  data_type _far = 90.0f;
};

}  // namespace VoxelEngine

/*
class Camera {
  using vec3 = glm::vec3;
  using mat4 = glm::mat4;
  using data_type = float;

 public:
  Camera() = default;
  virtual ~Camera() = 0;

  virtual vec3 direction() = 0;
  virtual vec3 right() = 0;
  virtual vec3 up() = 0;

  virtual mat4 projection() = 0;
  virtual mat4 view() = 0;
  virtual mat4 matrix() = 0;

  virtual data_type fov() = 0;
  virtual data_type aspect() = 0;
  virtual data_type near() = 0;
  virtual data_type far() = 0;

  virtual void moveInto(const vec3&) = 0;
  virtual void moveFor(const vec3&) = 0;
  virtual void rotateForAngle(const data_type&, const data_type&) = 0;
};
*/