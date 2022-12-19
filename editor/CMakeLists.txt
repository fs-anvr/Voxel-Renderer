cmake_minimum_required(VERSION 3.25)

project(
  Editor
  VERSION 0.0.1
  DESCRIPTION "Voxel engine editor"
  LANGUAGES CXX)


set(PRIVATE_SRC
  src/Primitives.cpp  
)


add_executable(${PROJECT_NAME} src/Main.cpp ${PRIVATE_SRC})

target_link_libraries(${PROJECT_NAME} Core)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
