#pragma once

// clang-format off

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// clang-format on

struct GLFWwindow;

namespace VoxelEngine {

class IO {
 public:
  static std::string FromFile(std::string filePath);
};

}  // namespace VoxelEngine
