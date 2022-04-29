cmake_minimum_required(VERSION 3.0)

project(hmspro CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()



add_subdirectory(muduo)
include_directories("muduo")
#include_directories("../src/")
#include_directories("../src/ajson/")
include_directories("/usr/include/mysql")



add_executable(hmspro "../src/HttpServer_test.cc"  "../src/MyDB.cc"  "../src/Dao.cc" )
target_link_libraries(hmspro muduo_net)
target_link_libraries(hmspro muduo_base)
target_link_libraries(hmspro muduo_http)
target_link_libraries(hmspro pthread rt)
target_link_libraries(hmspro mysqlclient)



