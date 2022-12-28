cmake_minimum_required(VERSION 3.25)

project(ServiceLocator)

set(PUBLIC_INCLUDE
  include/ServiceLocator/ServiceLocator.hpp
)

set(PRIVATE_SRC
  src/ServiceLocator.cpp
)

add_library(${PROJECT_NAME} STATIC
  ${PUBLIC_INCLUDE}
  ${PRIVATE_SRC}
)

add_library("VoxelEngine::${PROJECT_NAME}" ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    VoxelEngine::Render
    VoxelEngine::Scene
)