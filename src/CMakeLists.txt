# CMakeList.txt: Route Planning 的 CMake 项目，包括源和定义
# 此处特定于项目的逻辑。
#
cmake_minimum_required (VERSION 3.8)

#
# Set the binary executable name
#
set(project_BIN RoutePlanning)

#
# Find all executables
#
file(GLOB project_SRCS *.cpp *.h)

# 将源添加到此项目的可执行文件。
add_executable (${project_BIN} ${project_SRCS})

target_link_libraries(${project_BIN}
	PRIVATE io2d::io2d
	PUBLIC pugixml
)

#
# create a library for unit tests
#
add_library(route_planner OBJECT route_planner.cpp model.cpp route_model.cpp)
find_path(pugixml_INCLUDE_DIRS pugixml.hpp)
target_include_directories(route_planner PRIVATE ${pugixml_INCLUDE_DIRS})

if( ${CMAKE_SYSTEM_NAME} MATCHES "Linux" )
    target_link_libraries(${project_BIN} PUBLIC pthread)
endif()

if(MSVC)
	target_compile_options(${project_BIN} PUBLIC /D_SILENCE_CXX17_ALLOCATOR_VOID_DEPRECATION_WARNING /wd4459)
endif()