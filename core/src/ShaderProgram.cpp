#include "private/ShaderProgram.hpp"

#include <glad/gl.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace VoxelEngine {

class FileLoader {
 public:
  static std::string FromFile(std::string filePath) {
    std::string result;
    std::fstream stream(filePath, std::ios::in);
    result.assign(std::istreambuf_iterator<char>(stream), std::istreambuf_iterator<char>());
    stream.close();
    return std::move(result);
  }
};

ShaderProgram::ShaderProgram() : id(0) {}

ShaderProgram::ShaderProgram(std::string vertexFilePath, std::string fragmentFilePath) {
  id = LoadShaders(vertexFilePath, fragmentFilePath);
}

  GLuint ShaderProgram::LoadShaders(std::string vertexFilePath, std::string fragmentFilePath) {
    GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    std::string vertexShaderSource = FileLoader::FromFile(vertexFilePath);

    GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    std::string fragmentShaderSource = FileLoader::FromFile(fragmentFilePath);

    CompileShader(vertexShaderSource, vertexShaderID);

    CompileShader(fragmentShaderSource, fragmentShaderID);

    GLuint programID = CompileShaderProgram(vertexShaderID, fragmentShaderID);

    DeleteShader(vertexShaderID);
    DeleteShader(fragmentShaderID);

    return programID;
  }

  void ShaderProgram::CompileShader(std::string shaderSource, GLuint shaderID) {
    /* compile vertex shader */
    char const * VertexSourcePointer = shaderSource.c_str();
    glShaderSource(shaderID, 1, &VertexSourcePointer , NULL);
    glCompileShader(shaderID);

    GLint result = GL_FALSE;
    int infoLogLength = 0;

    /* check vertex shader */
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
    glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
    if (infoLogLength > 0) {
      char* errorMessage = new char[infoLogLength + 1];
      glGetShaderInfoLog(shaderID, infoLogLength, NULL, &errorMessage[0]);
      std::cout << std::string(errorMessage) << std::endl;
    }
  }

  GLuint ShaderProgram::CompileShaderProgram(GLuint vertexShaderID, GLuint fragmentShaderID) {
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
      glGetProgramInfoLog(programID, infoLogLength, NULL, &programErrorMessage[0]);
      std::string programMessage(programErrorMessage);
      std::cout << programMessage << std::endl;
    }

    return programID;
  }

}   // namespace VoxelEngine