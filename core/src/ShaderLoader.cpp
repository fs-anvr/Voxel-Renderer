#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <glad/gl.h>

#include "private/ShaderLoader.hpp"

namespace VoxelEngine {

  // это что за одна большая функция
  // перепиши нормально
  // ввод файлов отдельно
  // шейдеры отдельно
  // ввод можно в файловую систему закинуть отдельно от шейдеров

  // можно даже параллельно компилить шейдеры перед линковкой
  // при больших шейдерах будет быстрее работать

  GLuint ShaderLoader::LoadShaders(std::string vertexFilePath, std::string fragmentFilePath) {

    GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);

    std::string vertexShaderCode;
    std::fstream vertexShaderStream(vertexFilePath, std::ios::in);
    
    vertexShaderCode.assign((std::istreambuf_iterator<char>(vertexShaderStream)), std::istreambuf_iterator<char>());

    vertexShaderStream.close();
    //std::cout<< std::endl << std::endl << vertexShaderCode << std::endl << std::endl;



    GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    std::string fragmentShaderCode;
    std::fstream fragmentShaderStream(fragmentFilePath, std::ios::in);

    fragmentShaderCode.assign((std::istreambuf_iterator<char>(fragmentShaderStream)), std::istreambuf_iterator<char>());

    fragmentShaderStream.close();
    //std::cout<< std::endl << std::endl << fragmentShaderCode << std::endl << std::endl;

    GLint result = GL_FALSE;
    int infoLogLength = 0;

    /* compile vertex shader */
    char const * VertexSourcePointer = vertexShaderCode.c_str();
    glShaderSource(vertexShaderID, 1, &VertexSourcePointer , NULL);
    glCompileShader(vertexShaderID);

    /* check vertex shader */
      glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &result);
      glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
      if (infoLogLength > 0) {
        char* vertexShaderErrorMessage = new char[infoLogLength + 1];
        glGetShaderInfoLog(vertexShaderID, infoLogLength, NULL, &vertexShaderErrorMessage[0]);
        std::string vertexErrorMessage(vertexShaderErrorMessage);
        std::cout << vertexErrorMessage << std::endl;
      }

      /* compile fragment shader */
      char const * FragmentSourcePointer = fragmentShaderCode.c_str();
      glShaderSource(fragmentShaderID, 1, &FragmentSourcePointer , NULL);
      glCompileShader(fragmentShaderID);

      /* check fragment shader */
      glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &result);
      glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
      if ( infoLogLength > 0 ) {
        char* fragmentShaderErrorMessage = new char[infoLogLength + 1];
        glGetShaderInfoLog(fragmentShaderID, infoLogLength, NULL, &fragmentShaderErrorMessage[0]);
        std::string fragmentErrorMessage(fragmentShaderErrorMessage);
        std::cout << fragmentErrorMessage << std::endl;
      }

      /* compile shader program */
      GLuint ProgramID = glCreateProgram();
      glAttachShader(ProgramID, vertexShaderID);
      glAttachShader(ProgramID, fragmentShaderID);
      glLinkProgram(ProgramID);

      /* check shader program */
      glGetProgramiv(ProgramID, GL_LINK_STATUS, &result);
      glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &infoLogLength);
      if (infoLogLength > 0) {
        char* programErrorMessage = new char[infoLogLength + 1];
        glGetProgramInfoLog(ProgramID, infoLogLength, NULL, &programErrorMessage[0]);
        std::string programMessage(programErrorMessage);
        std::cout << programMessage << std::endl;
      }

      glDeleteShader(vertexShaderID);
      glDeleteShader(fragmentShaderID);

      return ProgramID;
    }

}   // namespace VoxelEngine