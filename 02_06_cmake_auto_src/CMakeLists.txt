#[[
    02_06_cmake_auto_src
        CMakeLists.txt
        main.cpp

    src
        xlog.cpp
        xtest.c
    include
        xlog.h
        xthread.hpp

]]


cmake_minimum_required(VERSION 3.20)
project(auto_src_h)

set(INCLUDE_PATH "./include")
include_directories(${INCLUDE_PATH})

aux_source_directory("." M_SRC)
aux_source_directory("./src" SRC)
# 讀取所有頭文件
file(GLOB H_FILE "${INCLUDE_PATH}/*.h*")


add_executable(${PROJECT_NAME} ${M_SRC} ${SRC} ${H_FILE})


