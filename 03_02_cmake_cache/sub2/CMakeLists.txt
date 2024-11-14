cmake_minimum_required(VERSION 3.20)
project(sub2)
set(SUB2_VAR1 "SUB2_VAR1")
message("@sub2_SUB2_VAR1=${SUB2_VAR1}")

# 同級目錄局部變量無法互相訪問
message("@sub2_SUB1_VAR1=${SUB1_VAR1}")
# 同級目錄的緩存變量可以訪問
message("@sub2_SUB1_CACHE_VAR1=${SUB1_CACHE_VAR1}")