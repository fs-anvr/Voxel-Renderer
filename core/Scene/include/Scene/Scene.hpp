#pragma once

#include <Time/Time.hpp>

// TODO: separate Time

namespace VoxelEngine {

class Scene {
 public:
  void Update();

  Time Time();

 private:
  VoxelEngine::Time time;
  // TODO: граф сцены, объекты, подпространстенное разбиение
};

}  // namespace VoxelEngine