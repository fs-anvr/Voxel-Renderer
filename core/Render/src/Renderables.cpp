/*
// clang-format off

#include <Render/Renderables.hpp>

// clang-format on

namespace VoxelEngine {

std::vector<std::reference_wrapper<Voxel>> Renderables::renderables;

void Renderables::Add(Voxel& voxel) { renderables.push_back(std::ref(voxel)); }

void Renderables::Clear() { renderables.clear(); }

std::vector<std::reference_wrapper<Voxel>> Renderables::Data() {
  return renderables;
}

}  // namespace VoxelEngine
*/