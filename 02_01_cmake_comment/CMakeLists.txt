# 測試message
cmake_minimum_required(VERSION 3.20)
project(test_comment)

message("parameter1")  # 測試message
message("parameter2" "parameter3" #[[注釋在message中]] "parameter4")

# message高級使用 - 指定日誌級別
# 進程退出，生成退出
# stderr
# message(FATAL_ERROR "Test FATAL_ERROR")
# message("after FATAL_ERROR")

# 進程繼續，生成退出
# 打印代碼路徑和行號
# stderr
message(SEND_ERROR "Test SEND_ERROR")
add_executable(test_comment test_message.cpp)
message("after SEND_ERROR")

# WARNING 打印代碼路徑和行號
# stderr
message(WARNING "Test WARNING")

# NOTICE 等同於none 也就是不加message("Test NOTICE")
# stderr
message(NOTICE "Test NOTICE")


# STATUS 加前綴-- 用戶可能感興趣的信息
# stdout
message(STATUS "Test Status")

# VERBOSE默認不顯示，用戶需要的詳細訊息,加前綴--
# stdout
message(VERBOSE "Test VERBOSE")

# 設置日誌顯示級別
# 標準輸出重定向到文件log.txt
# cmake -S . -B build --log-level=VERBOSE

# 標準錯誤輸出重定向到標準輸出
# cmake -S . -B build --log-level=VERBOSE > log.txt 2>&1

# DEBUG 加前綴--
message(DEBUG "Test DEBUG")

# TRACE 加前綴--
message(TRACE "Test TARCE")



# message Reporting checks查找庫日誌
# CHECK_PASS 紀錄檢查成功結果
# CHECK_FAIL 紀錄檢查失敗結果
# CHECK_START 開始記錄將要執行檢查的消息
message("=======================================")

message(CHECK_START "Find test")
# 查找test庫的代碼
# message消息縮進
set(CMAKE_MESSAGE_INDENT "  ")

# 嵌套查找
message(CHECK_START "Find xlog")
# 查找xlog代碼


message(CHECK_PASS "xlog found")


set(CMAKE_MESSAGE_INDENT "")
# 結束查找, 查找失敗
message(CHECK_FAIL "test Not found")