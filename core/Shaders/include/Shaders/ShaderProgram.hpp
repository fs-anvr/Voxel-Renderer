#pragma once

// clang-format off

#include <glad/gl.h>

#include <cstdint>
#include <string>

// clang-format on

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

  inline void DeleteShader(GLuint shaderID) { glDeleteShader(shaderID); }
};

}  // namespace VoxelEngine