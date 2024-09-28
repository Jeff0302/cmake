cmake_minimum_required(VERSION 3.20)

project(test_student)

# 指定頭文件查找路徑
include_directories("../student")

# 指定庫查找路徑
link_directories("../student/build/Debug")


add_executable(test_student test_student.cpp)

# 指定加載的庫
target_link_libraries(test_student static_library_example)
