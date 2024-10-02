cmake_minimum_required(VERSION 3.20)

# 引用頭文件路徑
include_directories("./student")

# 創建動態庫
# SHARED關鍵字創建動態庫
# windows系統下要導出動態庫，需要在頭文件添加__declspec(dllexport)宏
#             要導入動態庫，需要在頭文件添加__declspec(dllimport)宏

# 添加student庫編譯，項目會自帶預處理器變量student_EXPORTS宏
add_library(student SHARED "./student/student.cpp")

add_executable(test_student "./test_student/test_student.cpp")

# 執行文件與動態庫連結
target_link_libraries(test_student student)





