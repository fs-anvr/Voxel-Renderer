#include <Input/Input.hpp>
#include <Input/Keys.hpp>
#include <Render/Renderables.hpp>
#include <ServiceLocator/ServiceLocator.hpp>
#include <iostream>
#include <string>

#include "public/App.hpp"

class MyApp : public VoxelEngine::App {
 public:
  void Update() override {
    double deltaTime = VoxelEngine::ServiceLocator::Scene().Time().DeltaTime();
    static const double cameraRotateSpeed = 0.5;
    static const double cameraSpeed = 2.5;
    if (VoxelEngine::Input::IsPressed(
            VoxelEngine::KeyCode::MOUSE_RIGHT_BUTTON)) {
      VoxelEngine::ServiceLocator::Camera().RotateForAngle(
          cameraRotateSpeed * deltaTime *
              VoxelEngine::Input::Mouse::GetDeltaPos().first,
          cameraRotateSpeed * deltaTime *
              VoxelEngine::Input::Mouse::GetDeltaPos().second);
    }
    /*if
    (VoxelEngine::Input::IsReleased(VoxelEngine::KeyCode::MOUSE_RIGHT_BUTTON)) {
      std::cout <<
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB" <<
    std::endl;
    }*/

    if (VoxelEngine::Input::IsPressed(VoxelEngine::KeyCode::KEYBOARD_UPARROW) ||
        VoxelEngine::Input::IsRepeated(
            VoxelEngine::KeyCode::KEYBOARD_UPARROW)) {
      VoxelEngine::ServiceLocator::Camera().MoveFor(cameraSpeed * deltaTime,
                                                    0.0, 0.0);
    }
    if (VoxelEngine::Input::IsPressed(
            VoxelEngine::KeyCode::KEYBOARD_DOWNARROW) ||
        VoxelEngine::Input::IsRepeated(
            VoxelEngine::KeyCode::KEYBOARD_DOWNARROW)) {
      VoxelEngine::ServiceLocator::Camera().MoveFor(-cameraSpeed * deltaTime,
                                                    0.0, 0.0);
    }
    if (VoxelEngine::Input::IsPressed(
            VoxelEngine::KeyCode::KEYBOARD_RIGHTARROW) ||
        VoxelEngine::Input::IsRepeated(
            VoxelEngine::KeyCode::KEYBOARD_RIGHTARROW)) {
      VoxelEngine::ServiceLocator::Camera().MoveFor(
          0.0, cameraSpeed * deltaTime, 0.0);
    }
    if (VoxelEngine::Input::IsPressed(
            VoxelEngine::KeyCode::KEYBOARD_LEFTARROW) ||
        VoxelEngine::Input::IsRepeated(
            VoxelEngine::KeyCode::KEYBOARD_LEFTARROW)) {
      VoxelEngine::ServiceLocator::Camera().MoveFor(
          0.0, -cameraSpeed * deltaTime, 0.0);
    }
  }
};

int main() {
  using namespace std::string_literals;

  int width = 1366;
  int height = 768;
  std::string title = "Voxel Engine Editor"s;
  
  MyApp app;

  std::vector<VoxelEngine::Voxel> voxels;
  for (int x = 0; x < 10; ++x)
    for (int y = 0; y < 5; ++y)
      for (int z = 0; z < 5; ++z)
        voxels.push_back(VoxelEngine::Voxel{
            .position =
                glm::vec3{static_cast<float>(-x * 2), static_cast<float>(y * 2),
                          static_cast<float>(-z * 2)},
            .color = glm::vec3{(rand() % 10) * 0.1, (rand() % 10) * 0.1,
                               (rand() % 10) * 0.1}});
  VoxelEngine::Renderables::Assign(voxels.begin(), voxels.end());

  int returnCodeApp = app.Start(width, height, title);

  return returnCodeApp;
}