cmake_minimum_required(VERSION 3.15)
project(ps2emu C)

set(CMAKE_C_COMPILER clang)
set(CMAKE_C_COMPILER_ID Clang)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build (Debug/Release/RelWithDebInfo/MinSizeRel)" FORCE)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic -Weverything -Wno-padded -fcolor-diagnostics -march=native -Wno-pre-c23-compat")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g3 -O0 -fno-omit-frame-pointer -fsanitize=address,undefined -DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3 -flto -ffast-math -DNDEBUG")

add_executable(ps2emu ps2emu.c ps2emu.h)

target_include_directories(ps2emu PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

option(BUILD_TESTS "Build test suite" OFF)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

if(UNIX)
    target_link_libraries(ps2emu PRIVATE m)
endif()

