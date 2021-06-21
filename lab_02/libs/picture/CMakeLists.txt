cmake_minimum_required(VERSION 3.5)

project(picture LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME}
        src/picture.cpp
        src/point_transformations.cpp
        )

target_include_directories(${PROJECT_NAME} PRIVATE
        include/picture/
        src/
        )


add_subdirectory(libs/googletest)

add_executable(Google_Tests_run
        tests/test_matrix.cpp
        tests/test_point_transformations.cpp
        src/matrix.hpp
        src/point_transformations.cpp
        )

target_include_directories(Google_Tests_run PRIVATE
        include/picture/
        src/
        )

target_link_libraries(Google_Tests_run gtest gtest_main)
