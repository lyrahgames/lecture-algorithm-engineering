cmake_minimum_required(VERSION 2.8)

option(TARGET_MIC "compile for Intel Xeon Phi")

set(CMAKE_CXX_FLAGS "-std=c++11 -O3 -Wall -Werror -DNDEBUG")
if (TARGET_MIC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mmic")
endif()

add_executable(axpy axpy.cpp)

