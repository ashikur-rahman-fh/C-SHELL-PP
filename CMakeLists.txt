cmake_minimum_required(VERSION 3.14)

project(shell LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -------------------------------------------------------
# Shell implementation library
# -------------------------------------------------------

add_library(shell_lib
    src/command_executor.cpp
    src/repl.cpp
    src/executable.cpp
    src/parser.cpp
    src/builtins/builtin.cpp
    src/builtins/exit.cpp
    src/exe_builder.cpp
)

target_include_directories(shell_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/include/builtins
)

# -------------------------------------------------------
# Main executable
# -------------------------------------------------------

add_executable(shell
    src/main.cpp
)

target_link_libraries(shell
    PRIVATE shell_lib
)

# -------------------------------------------------------
# GoogleTest
# -------------------------------------------------------

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

# -------------------------------------------------------
# Tests
# -------------------------------------------------------

add_executable(shell_tests
    tests/parser_test.cpp
    src/parser.cpp
    src/executable.cpp
)

target_link_libraries(shell_tests
    PRIVATE
        shell_lib
        GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(shell_tests)
