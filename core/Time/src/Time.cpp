#include <Time/Time.hpp>
#include <chrono>

namespace VoxelEngine {

Time::Time() : previousFrame(Time::now()), currentFrame(Time::now()) {}

double Time::CurrentTime() noexcept {
  return std::chrono::duration<double>(
             std::chrono::time_point_cast<milliseconds>(Time::now())
                 .time_since_epoch())
      .count();
}

double Time::DeltaTime() {
  return Time::duration_to_double(currentFrame - previousFrame);
}

void Time::Update() {
  previousFrame = currentFrame;
  currentFrame = Time::now();
}

constexpr double Time::duration_to_double(
    const std::chrono::duration<int64_t, std::milli>& duration) noexcept {
  return std::chrono::duration<double>(duration).count();
}

Time::time_type Time::now() noexcept {
  return std::chrono::time_point_cast<milliseconds>(clock::now());
}

}  // namespace VoxelEngine