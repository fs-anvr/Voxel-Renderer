#include <App/App.hpp>
#include <Input/Input.hpp>
#include <Input/Keys.hpp>
#include <Render/Renderables.hpp>
#include <ServiceLocator/ServiceLocator.hpp>
#include <iostream>
#include <string>

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
          Primitives::Cube3D(5, VoxelEngine::ServiceLocator::Camera().position,
                             glm::vec3(1, 0.1, 0));
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
  }
};

int main() {
  using namespace std::string_literals;

  int width = 1366;
  int height = 768;
  std::string title = "Voxel Engine Editor"s;
  
  MyApp app;

  /*std::vector<VoxelEngine::Voxel> scatter;
  for (int x = 0; x < 10; ++x)
    for (int y = 0; y < 5; ++y)
      for (int z = 0; z < 5; ++z)
        scatter.push_back(VoxelEngine::Voxel{
            .position =
                glm::vec3{static_cast<float>(-x * 2), static_cast<float>(y * 2),
                          static_cast<float>(-z * 2)},
            .color = glm::vec3{(rand() % 10) * 0.1, (rand() % 10) * 0.1,
                               (rand() % 10) * 0.1}});

  auto shape = Primitives::Sphere3D(8, glm::vec3(15, 0, 30));
  auto shape1 = Primitives::Cube3D(5, glm::vec3(30, 0, 30));

  VoxelEngine::ServiceLocator::Scene().AddVoxels(scatter);
  VoxelEngine::ServiceLocator::Scene().AddVoxels(shape);
  VoxelEngine::ServiceLocator::Scene().AddVoxels(shape1);*/

  int returnCodeApp = app.Start(width, height, title);

  return returnCodeApp;
}