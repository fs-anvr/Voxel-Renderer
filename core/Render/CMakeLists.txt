cmake_minimum_required(VERSION 3.25)

project(Render)

set(PUBLIC_INCLUDE
  include/Render/Renderer.hpp
  include/Render/OpenGLRenderer.hpp
  include/Render/Camera.hpp
  include/Render/Renderables.hpp
)

set(PRIVATE_SRC
  src/Renderer.cpp
  src/OpenGLRenderer.cpp
  src/Camera.cpp
  src/Renderables.cpp
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
    VoxelEngine::Voxel
    VoxelEngine::Shaders
    VoxelEngine::ServiceLocator
    VoxelEngine::Scene

    glm::glm
    glad
)