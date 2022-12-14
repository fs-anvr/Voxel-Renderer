#include <GLFW/glfw3.h>

#include <Time/Time.hpp>

namespace VoxelEngine {

Time::Time() : previousFrame(0), currentFrame(0) {}

double Time::GetTime() { return currentFrame; }

double Time::DeltaTime() { return currentFrame - previousFrame; }

void Time::Update() {
  previousFrame = currentFrame;
  currentFrame = glfwGetTime();
}

}  // namespace VoxelEngine