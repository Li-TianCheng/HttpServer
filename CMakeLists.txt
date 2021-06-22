cmake_minimum_required(VERSION 3.17)
project(HttpServer)

set(CMAKE_CXX_STANDARD 14)

include_directories(./include ./modules)

add_subdirectory(modules)

add_executable(HttpServer main.cpp)

target_link_libraries(HttpServer Modules)