cmake_minimum_required(VERSION 3.29)
project(algabra)

set(CMAKE_CXX_STANDARD 20)


# Build executable
add_executable(algabra
        run.cpp
        func.h
        func.cpp
)
