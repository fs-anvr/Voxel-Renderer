#include <App/App.hpp>
#include <Input/Input.hpp>
#include <Input/Keys.hpp>
#include <Render/Renderables.hpp>
#include <ServiceLocator/ServiceLocator.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "Primitives.cpp"

class MyApp : public VoxelEngine::App {
 public:
  void Update() override {
    /*************************PROCESS INPUT*************************/

    double deltaTime = VoxelEngine::ServiceLocator::Scene().Time().DeltaTime();
    static const double cameraRotateSpeed = 0.08;
    static const double cameraSpeed = 1.5;
    if (VoxelEngine::Input::IsPressed(
            VoxelEngine::KeyCode::MOUSE_RIGHT_BUTTON)) {
      VoxelEngine::ServiceLocator::Camera().RotateForAngle(
          cameraRotateSpeed * deltaTime *
              VoxelEngine::Input::Mouse::GetDeltaPos().first,
          cameraRotateSpeed * deltaTime *
              VoxelEngine::Input::Mouse::GetDeltaPos().second);
    }
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

    /*************************GENERATE PRIMITIVES*************************/

    if (VoxelEngine::Input::IsPressed(VoxelEngine::KeyCode::KEYBOARD_F)) {
      auto cube =
          Primitives::Cube3DRandomColor(3, VoxelEngine::ServiceLocator::Camera().position);
      VoxelEngine::ServiceLocator::Scene().AddVoxels(cube);
    }

    if (VoxelEngine::Input::IsPressed(VoxelEngine::KeyCode::KEYBOARD_G)) {
      auto rectangle = Primitives::Rectangle3D(
          glm::vec3(1, 2, 3), VoxelEngine::ServiceLocator::Camera().position);
      VoxelEngine::ServiceLocator::Scene().AddVoxels(rectangle);
    }

    if (VoxelEngine::Input::IsPressed(VoxelEngine::KeyCode::KEYBOARD_H)) {
      auto sphere = Primitives::Sphere3D(
          5, VoxelEngine::ServiceLocator::Camera().position);
      VoxelEngine::ServiceLocator::Scene().AddVoxels(sphere);
    }

    if (VoxelEngine::Input::IsPressed(VoxelEngine::KeyCode::KEYBOARD_J)) {
      auto sphere = Primitives::Sphere3DRandomColor(
          10, VoxelEngine::ServiceLocator::Camera().position);
      VoxelEngine::ServiceLocator::Scene().AddVoxels(sphere);
    }

    auto snowman = Primitives::Snowman();
    VoxelEngine::ServiceLocator::Scene().AddVoxels(snowman);
  }
};

int main() {
  using namespace std::string_literals;

  int width = 1920;
  int height = 1080;
  std::string title = "Voxel Engine Editor"s;
  
  MyApp app;

  int returnCodeApp = app.Start(width, height, title);

  return returnCodeApp;
}