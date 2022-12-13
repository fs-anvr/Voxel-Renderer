#pragma once

#include "Time.hpp"

namespace VoxelEngine {

class Scene {
 public:
  void Update();

  Time Time();
 private:
  VoxelEngine::Time time;
  //TODO: граф сцены, объекты, подпространстенное разбиение
};

}  // namespace VoxelEngine