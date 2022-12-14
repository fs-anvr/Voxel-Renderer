// clang-format off

#include <Shaders/ShaderProgram.hpp>
#include <IO/IO.hpp>

#include <glad/gl.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// clang-format on

namespace VoxelEngine {

// TODO: вынести код обработки ошибок. а ещё лучше оформить callback'и

ShaderProgram::ShaderProgram() : id(0) {}

ShaderProgram::ShaderProgram(std::string vertexFilePath,
                             std::string fragmentFilePath) {
  id = LoadShaders(vertexFilePath, fragmentFilePath);
}

GLuint ShaderProgram::LoadShaders(std::string vertexFilePath,
                                  std::string fragmentFilePath) {
  GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
  std::string vertexShaderSource = IO::FromFile(vertexFilePath);

  GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
  std::string fragmentShaderSource = IO::FromFile(fragmentFilePath);

  CompileShader(vertexShaderSource, vertexShaderID);

  CompileShader(fragmentShaderSource, fragmentShaderID);

  GLuint programID = CompileShaderProgram(vertexShaderID, fragmentShaderID);

  DeleteShader(vertexShaderID);
  DeleteShader(fragmentShaderID);

  return programID;
}

void ShaderProgram::CompileShader(std::string shaderSource, GLuint shaderID) {
  /* compile shader */
  char const* VertexSourcePointer = shaderSource.c_str();
  glShaderSource(shaderID, 1, &VertexSourcePointer, NULL);
  glCompileShader(shaderID);

  GLint result = GL_FALSE;
  int infoLogLength = 0;

  /* check shader */
  glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
  glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
  if (infoLogLength > 0) {
    char* errorMessage = new char[infoLogLength + 1];
    glGetShaderInfoLog(shaderID, infoLogLength, NULL, &errorMessage[0]);
    std::cout << std::string(errorMessage) << std::endl;
  }
}

GLuint ShaderProgram::CompileShaderProgram(GLuint vertexShaderID,
                                           GLuint fragmentShaderID) {
  /* compile shader program */
  GLuint programID = glCreateProgram();
  glAttachShader(programID, vertexShaderID);
  glAttachShader(programID, fragmentShaderID);
  glLinkProgram(programID);

  GLint result = GL_FALSE;
  int infoLogLength = 0;

  /* check shader program */
  glGetProgramiv(programID, GL_LINK_STATUS, &result);
  glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);
  if (infoLogLength > 0) {
    char* programErrorMessage = new char[infoLogLength + 1];
    glGetProgramInfoLog(programID, infoLogLength, NULL,
                        &programErrorMessage[0]);
    std::string programMessage(programErrorMessage);
    std::cout << programMessage << std::endl;
  }

  return programID;
}

}  // namespace VoxelEngine