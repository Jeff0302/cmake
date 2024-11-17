cmake_minimum_required(VERSION 3.20)
project(cmake_math)

#[[
     math(EXPR 
          <variable> 
          "<expression>"
          [OUTPUT_FORMAT <format>])
]]#

set(exp "(3*10)+5")
math(EXPR out ${exp} OUTPUT_FORMAT DECIMAL) # 10進制
message("out=${out}")

set(exp "(3*10)+5")
math(EXPR out ${exp} OUTPUT_FORMAT HEXADECIMAL) # 16進制
message("out_hex=${out}")

