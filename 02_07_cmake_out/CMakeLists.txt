cmake_minimum_required(VERSION 3.20)
project(cmake_out)

set(INCLUDE_PATH "./student")
include_directories(${INCLUDE_PATH})

# 控制生成靜態庫或動態庫
# set(BUILD_SHARED_LIBS ON)
set(BUILD_SHARED_LIBS OFF)

# cmake傳遞變量給c++
add_definitions(-Dstudent_STATIC)
# linux動態庫.so
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib")

# 執行程序 dll動態庫輸出路徑
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/bin")
# 歸檔輸出路徑
# windows靜態庫.lib  windows動態庫地址.lib Linux靜態庫.a
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib")



add_library(student "./student/student.cpp")

# add_definitions(-Dstudent_STATIC)
add_executable(test_student "./test_student/test_student.cpp")

# 可執行文件連結庫
target_link_libraries(test_student student)

