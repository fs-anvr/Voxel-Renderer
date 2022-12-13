#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

struct GLFWwindow;

namespace VoxelEngine {

class IO {
 public:
  static std::string FromFile(std::string filePath);
};

}  // namespace VoxelEngine
