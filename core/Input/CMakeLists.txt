cmake_minimum_required(VERSION 3.25)

project(Input)

set(PUBLIC_INCLUDE
  include/Input/Input.hpp
  include/Input/Keys.hpp
)

set(PRIVATE_SRC
  src/Input.cpp
)

add_library(${PROJECT_NAME} STATIC
  ${PUBLIC_INCLUDE}
  ${PRIVATE_SRC}
)

#add_library(VoxeEngine::Input ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PRIVATE src)
