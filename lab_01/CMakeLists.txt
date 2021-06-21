cmake_minimum_required(VERSION 3.5)

project(lab_01 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)


include_directories(
        src/
        tests/
        )


add_executable(${PROJECT_NAME}
        src/main.cpp
        src/mainwindow.cpp
        src/mainwindow.ui
        src/canvas.cpp
        src/point_actions.cpp
        src/QCRectangle.cpp
        src/QCTriangle.cpp
        src/point_transformation.cpp
        )

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)


add_subdirectory(libs/googletest)

add_executable(Google_Tests_run
        tests/canvas_tests.cpp
        tests/point_tests.cpp

        src/QCRectangle.cpp
        src/QCTriangle.cpp
        src/canvas.cpp
        src/point_actions.cpp
        src/point_transformation.cpp
        src/mainwindow.cpp
        )

target_link_libraries(Google_Tests_run Qt${QT_VERSION_MAJOR}::Widgets)

target_link_libraries(Google_Tests_run gtest gtest_main)
