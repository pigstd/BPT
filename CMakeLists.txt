cmake_minimum_required(VERSION 3.22.1)
project(BPT)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

include_directories(src)

add_executable(code
    main.cpp
)