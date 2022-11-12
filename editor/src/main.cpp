#include <iostream>
#include <string>

#include "App.hpp"

class MyApp : public VoxelEngine::App {
  public:
    void Update() override {}
};

int main() {
  using namespace std::string_literals;

  int width = 1600;
  int height = 900;
  std::string title = "Voxel Engine Editor"s;
  
  MyApp app;

  int returnCodeApp = app.Start(width, height, title);

  return returnCodeApp;
}