#include "public/App.hpp"

#include <iostream>

#include "private/Window.hpp"

namespace VoxelEngine {

  App::App() {}

  App::~App() {}

  int App::Start(uint16_t width, uint16_t height, std::string title) {
    _window = new Window(width, height, title);

    eventDispatcher.AddListener<MouseMoveEvent>(
      [](MouseMoveEvent& event) {
          std::cout << event.format() << "MMMMMMMMOOOOOOOOOOVVVVVEEEEEEEEE" << std::endl;
      }
    );

    eventDispatcher.AddListener<MouseButtonPressEvent>(
      [](MouseButtonPressEvent& event) {
          std::cout << event.format() << "PRESSSSSSSSSSSSSSS" << std::endl;
      }
    );

    eventDispatcher.AddListener<MouseButtonReleaseEvent>(
      [](MouseButtonReleaseEvent& event) {
          std::cout << event.format() << "RELEEEEEEAAASSSSSEEEEEEEE" << std::endl;
      }
    );

    _window->setCallback([&](Event& event){
      eventDispatcher.Dispatch(event);
      //std::cout << event.format() << std::endl;
    });

    if (_window->IsInitialized() == false) return 1;

    while (_window->ShoudBeClose() == false) {
      _window->Update();
      this->Update();
    }
    return 0;
  }

}  // namespace VoxelEngine