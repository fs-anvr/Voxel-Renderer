cmake_minimum_required(VERSION 3.2)

set(ENGINE_PROJECT_NAME core)

project(${ENGINE_PROJECT_NAME})

set(ENGINE_PUBLIC_INCLUDES
  include/public/App.hpp
  include/public/IO.hpp
)

set(ENGINE_PRIVATE_INCLUDES
  include/private/Window.hpp
  include/private/Camera.hpp
  include/private/ShaderProgram.hpp
  include/private/Renderer.hpp
  include/private/VoxelModel.hpp
  include/private/Voxel.hpp
  include/private/Time.hpp
  include/private/Event.hpp
)

set(ENGINE_PRIVATE_SOURCES
  src/App.cpp
  src/Window.cpp
  src/Camera.cpp
  src/ShaderProgram.cpp
  src/Renderer.cpp
  src/IO.cpp
)

add_library(${ENGINE_PROJECT_NAME} STATIC
  ${ENGINE_PUBLIC_INCLUDES}
  ${ENGINE_PRIVATE_INCLUDES}
  ${ENGINE_PRIVATE_SOURCES}
)

target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC include)
target_include_directories(${ENGINE_PROJECT_NAME} PRIVATE src)
target_compile_features(${ENGINE_PROJECT_NAME} PUBLIC cxx_std_20)

add_subdirectory(../external/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glfw)

add_subdirectory(../external/glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glad)

add_subdirectory(../external/glm ${CMAKE_CURRENT_BINARY_DIR}/glm)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glm)