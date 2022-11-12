cmake_minimum_required(VERSION 3.2)

set(PROJECT_NAME glad)

add_library(${PROJECT_NAME} STATIC
  include/glad/gl.h
  src/gl.c
)

target_include_directories(${PROJECT_NAME} PUBLIC include)