cmake_minimum_required(VERSION 3.20)
project(cmake_cache)

#[[
set(<variable> <value> ... CACHE <type> <doc string> [FORCE])

type
    BOOL 
        ON/OFF 選擇框
    FILEPATH
        文件選擇
    PATH
        目錄選擇
    STRING
        字符串
    INTERNAL
        內部變量
doc_string
    變量說明
FORCE
    強制修改緩存，不設置第二次調用值改變不了

]]#

# 設置緩存變量 字符串類型
set(VAR1 "CACHE VAR1-1" CACHE STRING "set cache VAR1-1")
message(${VAR1})

# 緩存變量第二次修改不生效，須加上FORCE才會生效
set(VAR1 "CACHE VAR1-2" CACHE STRING "set cache VAR1-2")
message(${VAR1})

set(VAR1 "CACHE VAR1-3" CACHE STRING "set cache VAR1-3" FORCE)
message(${VAR1})



# CACHE變量作用域是全局的
# 普通變量作用域是自身和子模塊
set(VAR_NORMAL "VAR_NORMAL")
message("VAR_NORMAL= ${VAR_NORMAL}")

add_subdirectory("./sub1")
add_subdirectory("./sub2")

# 普通變量無法解決的問題
# 1.上級目錄無法訪問子目錄的局部變量
# 2.同級目錄局部變量無法互相訪問
message("@Main_SUB1_VAR1=${SUB1_VAR1}")
message("@Main_SUB2_VAR1=${SUB2_VAR1}")

# 上級目錄可以訪問子目錄的緩存變量
message("@Main_SUB1_CACHE_VAR1=${SUB1_CACHE_VAR1}")


# 不同類型範例
# BOOL
# 勾選BOOL
set(VAR_BOOL1 "ON" CACHE BOOL "VAR_BOOL1" FORCE)
set(VAR_BOOL2 "OFF" CACHE BOOL "VAR_BOOL2" )

# PATH/FILEPATH
# 選擇文件
set(VAR_FILEPATH1 "filepath" CACHE FILEPATH "VAR_FILEPATH1")
# 選擇目錄
set(VAR_PATH1 "path" CACHE PATH "VAR_PATH1")
# 內部緩存變量
set(VAR_INTERNAL "internal" CACHE INTERNAL "internal")

# BOOL緩存設置使用option
option(OPT1 "opt1" OFF)
option(OPT2 "opt2" ON)

# 普通變量
set(NORMAL_VAR "NORMAL_VAR")
# 設置緩存變量覆蓋同名變量策略
# OLD 刪除同名普通變量
# NEW 不刪除同名普通變量，要訪問CACHE使用$CACHE{var_name}
cmake_policy(SET CMP0126 NEW)


# CACHE變量
set(NORMAL_VAR "NORMAL_VAR_CACHE" CACHE STRING "CACHE VAR")
message("NORMAL_VAR=${NORMAL_VAR}")
# $CACHE{var_name} 直接查找緩存變量
message("CACHE{NORMAL_VAR}=$CACHE{NORMAL_VAR}")

# cmake命令傳遞緩存變量
# cmake -S . -B build -D <變量名>=<變量值>
message("PARA1=${PARA1}")
message("BUILD_SHARED_LIBS=${BUILD_SHARED_LIBS}")
