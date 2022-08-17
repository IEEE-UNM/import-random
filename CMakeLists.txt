# https://doc.qt.io/qt-6/cmake-get-started.html
cmake_minimum_required(VERSION 3.21.1)

project(import-random VERSION 1.0.0 LANGUAGES CXX)

# Configure project paths
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

# Exporting compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
# qt6_standard_project_setup()

add_subdirectory(src/import-random)
add_subdirectory(src/SpinningWheel)
