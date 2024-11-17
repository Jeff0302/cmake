cmake_minimum_required(VERSION 3.20)
project(cmake_env)

# 環境變量使用 全局無緩存
# 自定義環境變量
set(ENV{MYENV} "test env value")
message("MYENV=$ENV{MYENV}")

add_subdirectory("./sub1")
message("SUB1_ENV=$ENV{SUB1_ENV}")

# 系統環境變量
message("PATH=$ENV{PATH}")