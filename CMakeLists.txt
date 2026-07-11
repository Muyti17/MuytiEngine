cmake_minimum_required(VERSION 3.20)

project(MuytiEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    Engine/Core/include
)

add_executable(MuytiEngine

    Engine/Core/src/Application.cpp
    Engine/Core/src/Logger.cpp
    Samples/Sandbox/main.cpp 

)