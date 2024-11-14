cmake_minimum_required(VERSION 3.20)
project(sub1)

# 子模塊可以訪問上級目錄的變量
message("@sub1_VAR_NORMAL=${VAR_NORMAL}")

set(SUB1_VAR1 "SUB1_VAR1")
message("@sub1_SUB1_VAR1=${SUB1_VAR1}")

set(SUB1_CACHE_VAR1 "SUB1_CACHE_VAR1" CACHE STRING "SUB1_CACHE_VAR1")
