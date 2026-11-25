cmake_minimum_required(VERSION 3.20)

project(MemoryPerformanceLab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(memory_access_patterns
    experiments/01-memory-access-patterns/main.cpp
)

target_compile_options(memory_access_patterns PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)
