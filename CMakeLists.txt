cmake_minimum_required(VERSION 3.0)
project(cpp_stl_hw2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-std=c++0x")

add_executable(cpp_stl_hw2 main.cpp ListNode.h NodeWrapper.h LinkedList.h)