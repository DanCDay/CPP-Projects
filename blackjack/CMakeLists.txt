cmake_minimum_required(VERSION 3.25)
project(blackjack CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # build/compile_commands.json, read by clangd

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug) # debug info for the debugger
endif ()

# Add new .cpp files here as the project grows.
add_executable(${PROJECT_NAME} main.cpp)

target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall -Wextra -Wpedantic -pedantic-errors -Werror
    -Wconversion -Wsign-conversion -Wold-style-cast -Wshadow)
