cmake_minimum_required(VERSION 3.20)


project(test_student)
include_directories("../student")

link_libraries(student)

add_executable(test_student test_student.cpp)

# ���w�[�����w
target_link_libraries(test_student student)
