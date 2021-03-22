cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SFND_Kalman2D)

add_executable (sfnd_kalman2d src/main.cpp src/kalman_filter.cpp src/tracking.cpp)