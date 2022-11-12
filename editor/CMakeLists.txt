cmake_minimum_required(VERSION 3.2)

set(EDITOR_PROJECT_NAME editor)

project(${EDITOR_PROJECT_NAME})

add_executable(${EDITOR_PROJECT_NAME} src/main.cpp)

target_link_libraries(${EDITOR_PROJECT_NAME} core)

set_target_properties(${EDITOR_PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
target_compile_features(${EDITOR_PROJECT_NAME} PUBLIC cxx_std_20)
