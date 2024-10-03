cmake_minimum_required(VERSION 3.20)
project(message_color)

#[[
\033[1;31;40m  <!-- 1-高亮顯示 31-前景色紅色 40-背景色黑色 -->
\033[0m <!-- 採用終端默認設置, 即取消顏色設置 -->

顯示方式
0   終端默認顯示
1   高亮顯示
4   使用下劃線
5   閃爍
7   反白顯示
8   不可見

前景色      背景色      顏色
----------------------------------
30          40         黑色
31          41         紅色
32          42         綠色
33          43         黃色
34          44         藍色
35          45         紫紅色
36          46         青藍色
37          47         白色
]]
string(ASCII 27 Esc)

#Esc[1;31;40m
set(R "${Esc}[1;31;40m")
set(B "${Esc}[1;34;40m")
set(E "${Esc}[0m")


message("${R}red color${E} default color")
message("${B}blue color${E} default color")