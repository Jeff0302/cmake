cmake_minimum_required(VERSION 3.20)
project(cmake_math)

#[[
     math(EXPR 
          <variable> 
          "<expression>"
          [OUTPUT_FORMAT <format>])
]]#

set(exp "(3*10)+5")
math(EXPR out ${exp} OUTPUT_FORMAT DECIMAL) # 10�i��
message("out=${out}")

set(exp "(3*10)+5")
math(EXPR out ${exp} OUTPUT_FORMAT HEXADECIMAL) # 16�i��
message("out_hex=${out}")

