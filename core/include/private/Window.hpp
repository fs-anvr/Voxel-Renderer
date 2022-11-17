#pragma once

#include <cstdint>
#include <glm/glm.hpp>
#include <string>
#include <vector>

#include "VoxelModel.hpp"
#include "Renderer.hpp"

class GLFWwindow;
typedef unsigned int GLuint;

namespace VoxelEngine {

  class Window {

    struct InstanceData {
      glm::vec3 color;
      glm::vec3 offset;
    };

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
      bool _isInitialized; // костыль?

      GLuint _shaderProgram;  // костыль?

      VoxelModel _model;  // костыль?
      Renderer _renderer; // костыль?
  };

}  // namespace VoxelEngine