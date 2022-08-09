# https://doc.qt.io/qt-6/cmake-get-started.html
cmake_minimum_required(VERSION 3.21.1)

project(import-random VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

add_subdirectory(src/import-random)
add_subdirectory(src/SpinningWheel)
