cmake_minimum_required(VERSION 3.20)
project(Calculator LANGUAGES CXX)

add_executable(calculator src/main.cpp src/calculator/add_subtract.cpp)
target_include_directories(calculator PRIVATE include)
