cmake_minimum_required(VERSION 3.20)

project(student)

# 1.提供信息的變量PROJECT_NAME 對應project的name
# 2. 改變行為的變量BUILD_SHARED_LIBS ON動態庫 OFF靜態庫 默認OFF
# set(BUILD_SHARED_LIBS ON)
set(BUILD_SHARED_LIBS OFF)

# cmake傳遞變量給c++
add_definitions(-Dstudent_STATIC) # 默認值是1

# 3.描述系統變量
message("MSVC= " ${MSVC})
message("MINGW= " ${MINGW})
message("WIN32= " ${WIN32})
message("UNIX= " ${UNIX})
message("CMAKE_SYSTEM_NAME= " ${CMAKE_SYSTEM_NAME})

# 控制構建過程的變量 輸出控制 CMAKE_COLOR_MAKEFILE 生成makefile是否有顏色，默認是ON

# set(CMAKE_COLOR_MAKEFILE OFF)
add_library(${PROJECT_NAME} student.cpp student.h)







