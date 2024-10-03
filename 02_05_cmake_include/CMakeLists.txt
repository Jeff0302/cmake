cmake_minimum_required(VERSION 3.20)
project(cmake_include)
message("begin include")
include("cmake/test_cmake.cmake")
include("cmake/test_cmake.cmake")
# OPTIONAL 可選，文件不存在不報錯
include("cmake/test_cmake1.cmake" OPTIONAL)
include("cmake/test_cmake1.cmake" OPTIONAL RESULT_VARIABLE ret)  #
message("ret=${ret}") # NOTFOUND
include("cmake/test_cmake.cmake" OPTIONAL RESULT_VARIABLE ret)  #
message("ret=${ret}") # NOTFOUND

message("end include")
