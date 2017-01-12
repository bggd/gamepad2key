cmake_minimum_required(VERSION 3.7)

project(Gamepad2KeyProj)

set(SDL2_INC_PATH "" CACHE PATH "SDL2 include path")
set(SDL2_LIB_PATH "" CACHE PATH "SDL2 library path")

add_executable(Gamepad2Key src/main.cpp)

target_include_directories(Gamepad2Key PRIVATE ${SDL2_INC_PATH})

target_link_libraries(Gamepad2Key PRIVATE
  ${SDL2_LIB_PATH}/SDL2main.lib
  ${SDL2_LIB_PATH}/SDL2.lib
)

install(
  TARGETS Gamepad2Key
  RUNTIME DESTINATION bin
)

install(
  FILES ${SDL2_LIB_PATH}/SDL2.dll
  DESTINATION bin
)
