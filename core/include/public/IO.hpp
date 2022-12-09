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

class Mouse {
 public:
  static void BindKeysListener(void(*listener)(GLFWwindow*,int,int,int));
};

}  // namespace VoxelEngine
