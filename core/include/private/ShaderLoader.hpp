#include <cstdint>
#include <string>

typedef unsigned int GLuint;

namespace VoxelEngine {

  class ShaderLoader {
    public:
      static GLuint LoadShaders(std::string vertexFilePath, std::string fragmentFilePath);
  };

}  // namespace VoxelEngine