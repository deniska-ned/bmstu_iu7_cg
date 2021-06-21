cmake_minimum_required(VERSION 3.5)

project(lab_02 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt5Charts)

add_subdirectory(libs/picture)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/mainwindow.cpp
        src/mainwindow.hpp
        src/mainwindow.ui
        src/qt_picture_provider.cpp
        )

target_include_directories(${PROJECT_NAME} PRIVATE
        libs/picture/include/
        libs/picture/libs/matrix/include/
        )

target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Charts
        picture
        )
