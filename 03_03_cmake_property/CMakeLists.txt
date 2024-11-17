cmake_minimum_required(VERSION 3.20)

project(cmake_property)
#[[
    set_property(<GLOBAL                    |
                  DIRECTORY [<dir>]         |
                  TARGET    [<target1> ...] |
                  SOURCE    [<src1>..]  
                            [DIRECTORY <dirs>...]
                            [TARGET_DIRECTROY <targets>....]    |
                  INSTALL   [<file1> ...]   |
                  TEST      [<test1> ...]   |
                  CACHE     [<entry1> ...]  >
                  [APPEND] [APPEND_STRING]
                  PROPERTY <name>   [<value1> ...]
                )

    get_property(<variable>
                <GLOBAL                    |
                 DIRECTORY [<dir>]         |
                 TARGET    <target>        |
                 SOURCE    <source>  
                           [DIRECTORY <dir>]
                           [TARGET_DIRECTROY <target>]    |
                 INSTALL  <file1>   |
                 TEST     <test>    |
                 CACHE    <entry>   |
                 VARIABLE           >
            
                 PROPERTY <name>   
                [SET | DEFINED | BRIEF_DOCS | FULL_DOCS]
    
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
]]#

# 全局屬性
# 設置全局屬性
set_property(GLOBAL PROPERTY TEST_GLOBAL " test global 0001")

# 獲取全局屬性
get_property(val GLOBAL PROPERTY TEST_GLOBAL)
message("============================")
message("test global 0001=${val}")


# 訪問子目錄中的全局屬性 -> PASS(不需要緩存)
add_subdirectory("./sub1")
get_property(val GLOBAL PROPERTY SUB1_GLOBAL)
message("@Main_SUB1_GLOBAL=${val}")

# 目錄屬性
set_property(DIRECTORY . PROPERTY DIR1 "main_dir1")
get_property(var DIRECTORY . PROPERTY DIR1)
message("@Main_DIR1=${var}")
# 拿子目錄sub1的屬性
get_property(var DIRECTORY "./sub1" PROPERTY DIR1)
message("@sub1_DIR1=${var}")


# 文件屬性
set_property(SOURCE main.cpp PROPERTY S1 "S1 value")
get_property(val SOURCE main.cpp PROPERTY S1)
message("@Main_S1=${val}")

# cmake傳遞變量給c++
# cmake預置屬性COMPLIE_DEFINITIONS  傳遞預處理變量-DPARA1 1234
set_property(SOURCE main.cpp PROPERTY COMPILE_DEFINITIONS "PARA1=1234")
add_executable(${PROJECT_NAME} main.cpp)


# cmake目標屬性 *目標必須以已經存在
set_property(TARGET ${PROJECT_NAME} PROPERTY TVAR "tval")
get_property(var TARGET ${PROJECT_NAME} PROPERTY TVAR)
message("@Main_TVAR=${var}")

# 給c++傳遞宏
set_property(TARGET ${PROJECT_NAME} PROPERTY COMPILE_DEFINITIONS "PARA2=\"test_para2\"")
# 追加設定
set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY COMPILE_DEFINITIONS "PARA3=\"test_para3\"")


# 打印目標屬性
include(CMakePrintHelpers)
cmake_print_properties(TARGETS ${PROJECT_NAME} PROPERTIES COMPILE_DEFINITIONS TVAR)