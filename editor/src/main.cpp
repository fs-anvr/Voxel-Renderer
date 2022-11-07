#include <iostream>
#include <test.hpp>

int main() {
  int a = 5;
  int b = 10;
  std::cout << VoxelEngine::TestCore(a, b) << std::endl;
  VoxelEngine::TestGLFW();
  return 0;
}