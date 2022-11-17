#include <iostream>

#include "public/App.hpp"
#include "private/Window.hpp"

namespace VoxelEngine {

  App::App() {}

  App::~App() {}

  int App::Start(uint16_t width, uint16_t height, std::string title) {
    _window = new Window(width, height, title);

    if (_window->IsInitialized() == false) return 1;

    while (_window->ShoudBeClose() == false) {
      _window->Update();
      this->Update();
    }
    return 0;
  }

}  // namespace VoxelEngine