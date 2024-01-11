cmake_minimum_required(VERSION 3.24)

set(SOURCES
  cpp/compressionCalc.cpp
  cpp/process.cpp
)
set(HEADERS
  hpp/compressionCalc.h
  hpp/process.h
)

add_library(cs-Lib STATIC ${SOURCES} ${HEADERS})
target_compile_features(cs-Lib PUBLIC cxx_std_20)
target_compile_options(cs-Lib PRIVATE -Wall -Wextra -Wpedantic)
target_include_directories(cs-Lib PUBLIC hpp)

add_library(cs::Lib ALIAS cs-Lib)
