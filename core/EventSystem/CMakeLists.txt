cmake_minimum_required(VERSION 3.25)

project(EventSystem)

set(PUBLIC_INCLUDE
  include/EventSystem/EventSystem.hpp
  include/EventSystem/EventDispatcher.hpp
  include/EventSystem/Events/Event.hpp

  include/EventSystem/Events/MouseMoveEvent.hpp
  include/EventSystem/Events/MouseButtonPressEvent.hpp
  include/EventSystem/Events/MouseButtonReleaseEvent.hpp
  include/EventSystem/Events/KeyboardButtonPressEvent.hpp
  include/EventSystem/Events/KeyboardButtonReleaseEvent.hpp
  include/EventSystem/Events/KeyboardButtonRepeatEvent.hpp  
)

set(PRIVATE_SRC
  src/EventDispatcher.cpp
  
  src/MouseMoveEvent.cpp
  src/MouseButtonPressEvent.cpp
  src/MouseButtonReleaseEvent.cpp
  src/KeyboardButtonPressEvent.cpp
  src/KeyboardButtonReleaseEvent.cpp
  src/KeyboardButtonRepeatEvent.cpp
)

add_library(${PROJECT_NAME} STATIC
  ${PUBLIC_INCLUDE}
  ${PRIVATE_SRC}
)

add_library("VoxelEngine::${PROJECT_NAME}" ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME} PRIVATE VoxelEngine::Input)
