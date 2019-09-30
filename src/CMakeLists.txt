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