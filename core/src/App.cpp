#include "public/App.hpp"

#include <iostream>

#include "private/Window.hpp"
#include "private/Event.hpp"
#include "public/Input.hpp"
#include "public/ServiceLocator.hpp"

namespace VoxelEngine {

  App::App() {}

  App::~App() {}

  int App::Start(uint16_t width, uint16_t height, std::string title) {
    _window = new Window(width, height, title);

    eventDispatcher.AddListener<MouseMoveEvent>(
      [](MouseMoveEvent& event) {
        std::pair prevPos = Input::Mouse::GetPos();
        std::pair currentPos = event.Data();
        double xDelta = currentPos.first - prevPos.first;
        double yDelta = currentPos.second - prevPos.second;
        Input::Mouse::SetDeltaPos(xDelta, yDelta);
        Input::Mouse::SetPos(currentPos.first, currentPos.second);
      }
    );

    eventDispatcher.AddListener<MouseButtonPressEvent>(
      [](MouseButtonPressEvent& event) {
        Input::PressKey(event.button);
      }
    );

    eventDispatcher.AddListener<MouseButtonReleaseEvent>(
      [](MouseButtonReleaseEvent& event) {
        Input::ReleaseKey(event.button);
      }
    );

    eventDispatcher.AddListener<KeyboardButtonPressEvent>(
      [](KeyboardButtonPressEvent& event) {
        Input::PressKey(event.button);
      }
    );

    eventDispatcher.AddListener<KeyboardButtonReleaseEvent>(
      [](KeyboardButtonReleaseEvent& event) {
        Input::ReleaseKey(event.button);
      }
    );

    eventDispatcher.AddListener<KeyboardButtonRepeatEvent>(
      [](KeyboardButtonRepeatEvent& event) {
        Input::RepeatKey(event.button);
      }
    );

    _window->setCallback([&](Event& event){
      eventDispatcher.Dispatch(event);
      std::cout << event.format() << std::endl;
    });

    if (_window->IsInitialized() == false) return 1;

    while (_window->ShoudBeClose() == false) {
      ServiceLocator::Scene().Update();
      this->Update();
      _window->Update();
    }
    return 0;
  }

}  // namespace VoxelEngine