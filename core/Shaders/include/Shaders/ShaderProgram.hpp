#pragma once

// clang-format off

#include <cstdint>
#include <string>

// clang-format on

typedef unsigned int GLuint;

namespace VoxelEngine {

class ShaderProgram {
 public:
  GLuint id;

  ShaderProgram();
  ShaderProgram(std::string vertexFilePath, std::string fragmentFilePath);
  ~ShaderProgram() = default;

 private:
  GLuint LoadShaders(std::string vertexFilePath, std::string fragmentFilePath);

  void CompileShader(std::string shaderSource, GLuint shaderID);

  GLuint CompileShaderProgram(GLuint vertexShaderID, GLuint fragmentShaderID);

  void DeleteShader(GLuint shaderID);
};

}  // namespace VoxelEngine