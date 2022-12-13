#pragma once

#include <GLFW/glfw3.h>

namespace VoxelEngine {

class Time {
 public:
  double GetTime() {
    return currentFrame;
  }

  double DeltaTime() {
    return currentFrame - previousFrame;
  }

  Time() : previousFrame(0), currentFrame(0) {}

  void Update() {
    previousFrame = currentFrame;
    currentFrame = glfwGetTime();
  }

 private:
  double previousFrame;
  double currentFrame;
};

}  // namespace VoxelEngine