#include "public/Scene.hpp"

namespace VoxelEngine {

void Scene::Update() {
  time.Update();
}

Time Scene::Time() {
  return time;
}

}  // namespace VoxelEngine