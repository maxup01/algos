cmake_minimum_required(VERSION 3.16)

project(algos
    VERSION 0.1.0
    DESCRIPTION "Algorithms and data structures library"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(algos STATIC
    src/union_find.c
)

target_include_directories(algos PUBLIC include)

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
    target_compile_options(algos PRIVATE -Wall -Wextra -Wpedantic)
endif()
