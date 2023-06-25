cmake_minimum_required(VERSION 3.20)

project(PacManClone)

include(FetchContent)


FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/4.2.0.zip
)

FetchContent_MakeAvailable(raylib)


add_subdirectory(${CMAKE_SOURCE_DIR}/src)
