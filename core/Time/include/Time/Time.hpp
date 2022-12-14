#pragma once

namespace VoxelEngine {

class Time {
 public:
  Time();

  ~Time() = default;

  double GetTime();

  double DeltaTime();

  void Update();

 private:
  double previousFrame;
  double currentFrame;
};

}  // namespace VoxelEngine