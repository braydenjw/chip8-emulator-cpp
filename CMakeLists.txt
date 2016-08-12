cmake_minimum_required(VERSION 3.6)
project(chip8_emulator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp opcode.cpp opcode.h rom.cpp rom.h)
add_executable(chip8_emulator ${SOURCE_FILES})