#pragma once

#include <EventSystem/EventSystem.hpp>
#include <cstdint>
#include <string>

namespace VoxelEngine {

class Window;

class App {
 public:
  App();
  virtual ~App();

  App(const App&) = delete;
  App(App&&) = delete;
  App& operator=(const App&) = delete;
  App& operator=(App&&) = delete;

  virtual int Start(uint16_t width, uint16_t height, std::string title);

  virtual void Update() {}

 private:
  Window* _window;
  EventDispatcher eventDispatcher;
};

}  // namespace VoxelEngine