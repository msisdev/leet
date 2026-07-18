cmake_minimum_required(VERSION 3.16)
project(leet_cpp VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB PROBLEM_SOURCES CONFIGURE_DEPENDS problems/*.cpp)

add_executable(leet_runner
    src/main.cpp
    ${PROBLEM_SOURCES}
)

target_include_directories(leet_runner PRIVATE include)
