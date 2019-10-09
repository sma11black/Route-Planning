# CMakeList.txt : 顶级 CMake 项目文件，执行全局配置
# 和此处的包含子项目。
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

project ("Route Planning")

# set(CMAKE_TOOLCHAIN_FILE "D:/Workspace/VisualStudioProjects/vcpkg/scripts/buildsystems/vcpkg.cmake")

#
# Project Output Paths
#
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")

#
# Locate Project Prerequisites
#
find_package(pugixml CONFIG REQUIRED)
find_package(io2d REQUIRED)
find_package(unofficial-cairo)
find_package(unofficial-graphicsmagick)
find_package(GTest CONFIG REQUIRED)

# 包含子项目。
set(IO2D_WITHOUT_SAMPLES 1)
set(IO2D_WITHOUT_TESTS 1)
add_subdirectory ("src")
add_subdirectory ("test")
