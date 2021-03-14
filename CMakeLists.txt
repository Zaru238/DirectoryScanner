cmake_minimum_required(VERSION 3.5)
project(Template LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS thread system log)

SET(Boost_USE_STATIC_LIBS ON)

add_subdirectory(common)
add_subdirectory(server)
add_subdirectory(client)
