cmake_minimum_required (VERSION 3.8)

# GTest
enable_testing()

# Unit Tests
# message("TESTING = ${TESTING}")

# choose which test .cpp file
add_executable(test utest_route_model_class.cpp)

SET(GTest_LIBS GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
target_link_libraries(test PRIVATE GTest::gtest_main ../src/route_planner.dir/Debug/route_planner pugixml)
add_test(NAME TestsRoutePlanning COMMAND test)

unset(TESTING CACHE)