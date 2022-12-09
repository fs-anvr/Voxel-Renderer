#pragma once

#include <GLFW/glfw3.h>

namespace VoxelEngine {

class Time {
 public:
  double GetTime() {
    return currentFrame;
  }

  double GetDeltaTime() {
    return currentFrame - previousFrame;
  }

  Time() : previousFrame(0), currentFrame(0) {}

 private:
  void Update() {
    previousFrame = currentFrame;
    currentFrame = glfwGetTime();
  }

  double previousFrame;
  double currentFrame;
};

}  // namespace VoxelEngine