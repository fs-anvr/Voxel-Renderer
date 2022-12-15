cmake_minimum_required(VERSION 3.25)

project(Voxel)

set(PUBLIC_INCLUDE
  include/Voxel/Voxel.hpp
)

add_library(${PROJECT_NAME} STATIC
  ${PUBLIC_INCLUDE}
)

add_library("VoxelEngine::${PROJECT_NAME}" ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC include)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    glm::glm
)