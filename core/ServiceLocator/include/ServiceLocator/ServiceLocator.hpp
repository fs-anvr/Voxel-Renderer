#pragma once

// clang-format off

#include <Render/Camera.hpp>
#include <Render/Renderer.hpp>
#include <Render/OpenGLRenderer.hpp>
#include <Scene/Scene.hpp>

// clang-format on

namespace VoxelEngine {

class ServiceLocator {
 public:
  static Camera& Camera() {
    static VoxelEngine::Camera instance = VoxelEngine::Camera();
    return instance;
  }

  static Scene& Scene() {
    static VoxelEngine::Scene instance = VoxelEngine::Scene();
    return instance;
  }

  static Renderer& Renderer() {
    static OpenGLRenderer instance = VoxelEngine::OpenGLRenderer();
    return instance;
  }

  /* data */
 private:
  ServiceLocator() = delete;
  ~ServiceLocator() = delete;
};

}  // namespace VoxelEngine