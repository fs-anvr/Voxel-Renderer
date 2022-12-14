cmake_minimum_required(VERSION 3.25)

project(IO)

set(PUBLIC_INCLUDE
  include/IO/IO.hpp
)

set(PRIVATE_SRC
  src/IO.cpp
)

add_library(${PROJECT_NAME} STATIC
  ${PUBLIC_INCLUDE}
  ${PRIVATE_SRC}
)

add_library("VoxelEngine::${PROJECT_NAME}" ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PRIVATE src)