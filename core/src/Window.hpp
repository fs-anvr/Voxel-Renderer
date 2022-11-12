#pragma once

#include <cstdint>
#include <string>

class GLFWwindow;

namespace VoxelEngine {

  class Window {
    public:
      Window(uint16_t width, uint16_t height, std::string title);
      ~Window();

      void Update();

      int ShoudBeClose();

      uint16_t Width() const { return _width; }
      uint16_t Height() const { return _height; }
      std::string Title() const { return _title; }
      bool IsInitialized() const { return _isInitialized; }

    private:
      bool Init();

      Window(const Window&) = delete;
      Window(Window&&) = delete;
      Window& operator=(const Window&) = delete;
      Window& operator=(Window&&) = delete;

      uint16_t _width;
      uint16_t _height;
      std::string _title;

      GLFWwindow* _window;
      bool _isInitialized;
  };

}  // namespace VoxelEngine