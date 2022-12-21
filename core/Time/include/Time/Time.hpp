#pragma once

#include <chrono>

namespace VoxelEngine {

class Time {
 public:
  using clock = std::chrono::steady_clock;
  using seconds = std::chrono::seconds;
  using milliseconds = std::chrono::milliseconds;

  using time_type = std::chrono::time_point<clock, milliseconds>;

  Time();

  ~Time() = default;

  double CurrentTime() noexcept;

  double DeltaTime();

  void Update();

 private:
  time_type previousFrame;
  time_type currentFrame;

  static constexpr double duration_to_double(const std::chrono::duration<int64_t, std::milli>& duration) noexcept;
  
  static time_type now() noexcept;
};

}  // namespace VoxelEngine