#include <Scene/Scene.hpp>

namespace VoxelEngine {

void Scene::Update() { time.Update(); }

Time Scene::Time() { return time; }

void Scene::AddVoxel(const Voxel& voxel) { objects.push_back(voxel); }

std::vector<Voxel> Scene::GetVoxels() const { return objects; }

}  // namespace VoxelEngine