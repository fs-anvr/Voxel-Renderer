#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace VoxelEngine {

class IO {
 public:
  static std::string FromFile(std::string filePath);
};

}  // namespace VoxelEngine
