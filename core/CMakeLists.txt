cmake_minimum_required(VERSION 3.2)

project(core)

add_library(core STATIC
  src/test.cpp
  includes/test.hpp
  )

target_include_directories(core PUBLIC includes)