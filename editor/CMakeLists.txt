cmake_minimum_required(VERSION 3.2)

project(editor)

add_executable(editor src/main.cpp)

target_link_libraries(editor core)

set_target_properties(editor PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
