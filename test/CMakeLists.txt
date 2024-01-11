cmake_minimum_required(VERSION 3.24)
project(cs_Test CXX)

if(NOT TARGET cs::Lib)
  find_package(cs::Lib CONFIG REQUIRED)
endif()

add_executable(cs_Test test_rle_Compress.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest GTest::gtest_main
                                              cs::Lib)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME} TEST_PREFIX "cs_Test::")
