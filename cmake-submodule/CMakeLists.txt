cmake_minimum_required(VERSION 3.0)

project(echo CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

add_subdirectory(muduo)
include_directories("muduo")

add_executable(echo ../src/echo.cc)
target_link_libraries(echo muduo_net)
target_link_libraries(echo muduo_base)
target_link_libraries(echo pthread rt)


add_executable(cbpro ../src/HttpServer_test.cc)
target_link_libraries(cbpro muduo_net)
target_link_libraries(cbpro muduo_base)
target_link_libraries(cbpro muduo_http)
target_link_libraries(cbpro pthread rt)
