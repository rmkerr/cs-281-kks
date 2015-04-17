cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall ${CMAKE_CXX_FLAGS} -g")
add_executable(tests tests.cxx Loader.cxx Logger.cxx Scheduler.cxx Task.cxx Schedule.cxx)