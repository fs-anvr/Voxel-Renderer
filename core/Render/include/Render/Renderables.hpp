/*
#pragma once

// clang-format off

#include <Voxel/Voxel.hpp>

#include <vector>
#include <functional>

// clang-format on

namespace VoxelEngine {

class Renderables {
 public:
  static void Add(Voxel& voxel);

  static void Clear();

  template <typename Iter>
  static void Assign(Iter begin, Iter end) {
    Renderables::Clear();
    renderables.assign(begin, end);
  }

  static std::vector<std::reference_wrapper<Voxel>> Data();

 private:
  static std::vector<std::reference_wrapper<Voxel>> renderables;
};

}  // namespace VoxelEngine
*/