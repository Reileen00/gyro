cmake_minimum_required(VERSION 3.12)
project(gyro LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(Eigen3 REQUIRED)
find_package(pybind11 REQUIRED)

pybind11_add_module(gyro src/bindings.cpp)

target_include_directories(gyro PRIVATE include)
target_link_libraries(gyro PRIVATE Eigen3::Eigen)
