#pragma once

#include "private/Camera.hpp"
#include "public/Scene.hpp"

namespace VoxelEngine {

class ServiceLocator {
 public:
  static inline Camera& Camera() {
    static VoxelEngine::Camera instance = VoxelEngine::Camera();
    return instance;
  }

  static inline Scene& Scene() {
    static VoxelEngine::Scene instance = VoxelEngine::Scene();
    return instance;
  }
  /* data */
 private:
  ServiceLocator() = delete;
  ~ServiceLocator() = delete;
};

}  // namespace VoxelEngine