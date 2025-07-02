
cmake_minimum_required(VERSION 4.0.3)
project(CounterStrike15)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(CounterStrike15)

add_subdirectory(vendor/SDL3)
add_subdirectory(vender/GLFW)
add_subdirectory(vendor/cstrike15_src)
