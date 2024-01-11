cmake_minimum_required(VERSION 3.24)
project(cs)

set(CMAKE_FIND_PACKAGE_PREFER_CONFIG ON)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_subdirectory(lib)
include(GNUInstallDirs)

add_executable(cs main.cpp)
target_link_libraries(cs PRIVATE cs-Lib)
target_compile_features(cs INTERFACE cxx_std_20)
target_compile_options(cs PRIVATE -Wall -Wextra -Wpedantic)
target_compile_options(cs PRIVATE "$<$<CONFIG:Debug>:-O0>")
install(TARGETS cs EXPORT cs-targets)
