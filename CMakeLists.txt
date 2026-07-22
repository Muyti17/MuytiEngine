cmake_minimum_required(VERSION 3.20)

project(MuytiEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    Engine/Core/include
    Engine/Platform/Windows
    Engine/Platform
    )

add_executable(MuytiEngine

    Engine/Core/src/Application.cpp
    Engine/Core/src/Logger.cpp
    Samples/Sandbox/main.cpp 
    Engine/Platform/Windows/WindowsWindow.cpp
)

target_compile_definitions(MuytiEngine PRIVATE UNICODE _UNICODE)