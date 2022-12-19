#pragma once

#include <Time/Time.hpp>
#include <Voxel/Voxel.hpp>
#include <vector>
// #include <concepts>

// TODO: separate Time

namespace VoxelEngine {

// TODO: починить gcc (или удалить)
// у меня не обновляется gcc и из-за этого я не могу использовать 20 стандарт
// это проблема будет решена в ближайшее время

/*

template<class T>
concept Iterable = requires (T t) {
  t.begin();
  t.end();
  *(t.begin());
  t.begin() + 1;
};

*/

class Scene {
 public:
  void Update();

  Time Time();

  void AddVoxel(const Voxel& voxel);

  /*

  template<Iterable Container>
  void AddVoxels(const Container& voxels) {
    objects.emplace_back(voxels.begin(), voxels.end());

  }
  */

  template <class Container>
  void AddVoxels(const Container& voxels) {
    for (auto voxel : voxels) {
      objects.push_back(voxel);
    }
  }

  std::vector<Voxel> GetVoxels() const;

 private:
  VoxelEngine::Time time;
  // TODO: граф сцены, объекты, подпространстенное разбиение, хранение разных
  // типов вокселей
  std::vector<Voxel> objects;
};

}  // namespace VoxelEngine