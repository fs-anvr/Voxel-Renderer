cmake_minimum_required(VERSION 3.25)

project(Render)

set(PUBLIC_INCLUDE
  include/Render/Renderer.hpp
  include/Render/Camera.hpp
)

set(PRIVATE_SRC
  src/Renderer.cpp
  src/Camera.cpp
)

add_library(${PROJECT_NAME} STATIC
  ${PUBLIC_INCLUDE}
  ${PRIVATE_SRC}
)

add_library("VoxelEngine::${PROJECT_NAME}" ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME} PRIVATE VoxelEngine::Voxel)
target_link_libraries(${PROJECT_NAME} PUBLIC glm::glm)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC glad)