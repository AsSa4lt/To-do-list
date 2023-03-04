cmake_minimum_required(VERSION 3.24)
project(To_do_list)

set(CMAKE_CXX_STANDARD 17)

add_executable(To_do_list main.cpp Task.cpp Task.h TaskList.cpp TaskList.h)
