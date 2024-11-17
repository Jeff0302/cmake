cmake_minimum_required(VERSION 3.20)
project(sub1)

set_property(GLOBAL PROPERTY SUB1_GLOBAL "sub1_global_property")

get_property(sub1_val GLOBAL PROPERTY SUB1_GLOBAL)

message("@sub1_SUB1_GLOBAL=${sub1_val}")

# APPEND
# APPEND 數組方式添加 TEST_APPEND= append 001;append 002;append 003
set_property(GLOBAL APPEND PROPERTY TEST_APPEND "append 001")
set_property(GLOBAL APPEND PROPERTY TEST_APPEND "append 002")
set_property(GLOBAL APPEND PROPERTY TEST_APPEND "append 003")
get_property(val GLOBAL PROPERTY TEST_APPEND)

message("@sub1_TEST_APPEND=${val}")

# APPEND_STRING
# APPEND_STRING 以字符串方式添加 TEST_APPEND= append 001;append 002;append 003
set_property(GLOBAL APPEND PROPERTY TEST_APPEND_STRING "append 001")
set_property(GLOBAL APPEND PROPERTY TEST_APPEND_STRING "append 002")
set_property(GLOBAL APPEND PROPERTY TEST_APPEND_STRING "append 003")
get_property(val GLOBAL PROPERTY TEST_APPEND_STRING)

message("@sub1_TEST_APPEND_STRING=${val}")

# get_property SET | DEFINED
set_property(GLOBAL PROPERTY P1 "p1")
get_property(var GLOBAL PROPERTY P1 SET)
message("@sub1_P1=${var}")

if(var)
    message("P1 is set")
else()
    message("P1 not set")
endif()

# 只有調用define_property之後才會為1
get_property(var GLOBAL PROPERTY P1 DEFINED)
message("@sub1_P1=${var}")
if(var)
    message("P1 is defined")
else()
    message("P1 not defined")
endif()



#[[
    define_property(<GLOBAL     | 
                     DIRECTORY  | 
                     TARGET     | 
                     SOURCE     |
                     TEST       |
                     VARIABLE   | 
                     CACHED_VARIABLE>
                     
                     PROPERTY <name> [INHERITED]
                     [BRIEF_DOCS <brief-doc> [docs...] ]
                     [FULL_DOCS <full-doc> [docs...] ]
                     [INITIALIZE_FROM_VARIABLE <variable>])  

]]##
# 定義屬性 不需要賦值
define_property(GLOBAL PROPERTY TEST_DEF BRIEF_DOCS "TEST_DEF brief docs")
get_property(var GLOBAL PROPERTY TEST_DEF DEFINED)
message("@sub1_TEST_DEF=${var}")

# 獲取屬性概要說明
get_property(var GLOBAL PROPERTY TEST_DEF BRIEF_DOCS)
message("@sub1_TEST_DEF_BRIEF_DOCS=${var}")


# 目錄屬性
set_property(DIRECTORY . PROPERTY DIR1 "dir001")
get_property(var DIRECTORY . PROPERTY DIR1)
message("@sub1_DIR1=${var}")

get_property(var DIRECTORY "../../03_03_cmake_property" PROPERTY DIRM)
message("@Main_DIR1=${var}")
