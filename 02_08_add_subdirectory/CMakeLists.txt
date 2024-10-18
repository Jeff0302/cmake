cmake_minimum_required(VERSION 3.20)

project(example)


set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib")

# ÀRºA®w
set(BUILD_SHARED_LIBS OFF)
add_definitions(-Dstudent_STATIC)
# °ÊºA®w
#set(BUILD_SHARED_LIBS ON)

add_subdirectory("./student") 
add_subdirectory("./test_student")