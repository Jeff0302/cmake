cmake_minimum_required(VERSION 3.20)
project(test_set)
# 設置變量
set(VAR1 "test VAR1 value")

message("=====================================")
# 訪問變量${變量名}
message("VAR1=" ${VAR1})
message("VAR1 in string ${VAR1}")
# \為轉義字符
message("\${VAR1}=${VAR1}")



set(VAR2 "VAR1")
message("VAR2=" ${VAR2})
message("VAR2=" ${${VAR2}})



# 取消變量
unset(VAR1)
# 取消後返回空串
message("VAR1=" ${VAR1})