cmake_minimum_required(VERSION 3.25)

project(ServiceLocator)

set(PUBLIC_INCLUDE
  include/ServiceLocator/ServiceLocator.hpp
)

add_library(${PROJECT_NAME} STATIC
  ${PUBLIC_INCLUDE}
)

add_library("VoxelEngine::${PROJECT_NAME}" ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PRIVATE VoxelEngine::Render)
target_link_libraries(${PROJECT_NAME} PRIVATE VoxelEngine::Scene)