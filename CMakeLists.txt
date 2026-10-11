cmake_minimum_required(VERSION 3.20)
project(Calculator LANGUAGES CXX)

add_executable(calculator src/main.cpp)
target_sources(calculator PRIVATE src/ui/console_animation.cpp)
target_include_directories(calculator PRIVATE include)
target_sources(calculator PRIVATE src/ui/basic_layout.cpp)
