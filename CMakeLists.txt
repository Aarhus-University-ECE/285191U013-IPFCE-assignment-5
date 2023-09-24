cmake_minimum_required(VERSION 3.16)
project(assignment-5 VERSION 0.1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20) # Needed to use designated initializers in ./tests/tests.cpp
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set(CMAKE_C_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
		Catch2
		GIT_REPOSITORY https://github.com/catchorg/Catch2.git
		GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_library(circle STATIC circle.c)
target_compile_definitions(circle PRIVATE -DTEST)
add_library(jolly_jumper STATIC jolly_jumper.c)
target_compile_definitions(jolly_jumper PRIVATE -DTEST)

add_executable(unit-tests tests/tests.cpp)
target_include_directories(unit-tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(unit-tests circle jolly_jumper)
target_link_libraries(unit-tests Catch2::Catch2WithMain)
target_compile_definitions(unit-tests PRIVATE -DTEST)
