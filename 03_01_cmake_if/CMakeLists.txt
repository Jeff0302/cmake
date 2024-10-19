cmake_minimum_required(VERSION 3.20)

project(cmake_if)

#[[
    if(<condition>)    
        <command>
    elseif(<condition>) # optional block, can be repeated
        <command>
    else()
        <command>       # optional block
    endif()

]]

#[[
    if(<盽秖>)  # 盽秖
    狦盽秖琌1, ON, YES, TRUE , Y┪獶箂计(珹疊翴计)玥痷
    狦盽秖琌0, OFF, NO, FALSE, N, IGNORE, NOTFOUND, 才﹃, ┪-NOTFOUND挡Ю玥安
]]

if(1)
    message("1 is TRUE")
endif()


if(0)
    message("0 is TRUE")
else()
    message("0 is False")
endif()


if(OFF)
    message("OFF is TRUE")
elseif(NO)
    message("NO is TRUE")
else()
    message("NO is FALSE")
endif()

if()
    message("empty is TRUE")
else()
    message("empty is FALSE")
endif()

if(-1)
    message("-1 is TRUE")
endif()

if(333)
    message("333 is TRUE")
endif()

if(0.1)
    message("0.1 is TRUE")
endif()

if(-NOTFOUND)
    message("-NOTFOUND is TRUE")
else()
    message("-NOTFOUND is FALSE")
endif()


#[[
    if(<variable>)
    狦倒﹚獶安盽秖跑秖玥痷玥安ゼ﹚竡跑秖
    Щ把计ぃ琌跑秖吏挂跑秖if(ENV{some_var})羆琌穦蝶︳安
]]

if(VAR_NOT_DEF)
    message("VAR_NOT_DEF is TRUE")
else()
    message("VAR_NOT_DEF is FALSE")
endif()

SET(VAR1_TRUE TRUE)

if(VAR1_TRUE)
    message("VAR1_TRUE is TRUE")
else()
    message("VAR1_TRUE is FALSE")
endif()

#[[
    if(<string>)
    ま腹才﹃璸衡FALSE埃獶才﹃琌痷タ盽秖ぇ
]]

if("TRUE")
    message("string TRUE is TRUE")
endif()

if("ON")
    message("string ON is TRUE")
endif()

if("test")
    message("string test is TRUE")
else()
    message("string test is FALSE")
endif()



#[[

じ耞
1. EXISTS
2. COMMAND
3. DFINED

じ耞
1. EQUAL, LESS, LESS_EQUAL, GREATER, GREATER_EQUAL(计)
2. STREQUAL, STRLESS, STRLESS_EQUAL, STRGREATER, STRGREATER_EQUAL(才﹃)
3. VERSION_EQUAL, VERSION_LESS, VERSION_LESS_EQUAL, VERSION_GREATER, VERSION_GREATER_EQUAL
4. MATCHS
   if(<variable | string> MATCHES regex)

 ]]

set(VAR_DEF OFF)

if(DEFINED VAR_DEF)
    message("VAR_DEF is DEFINED")
endif()

if(DEFINED VAR_NOT_DEF)
    message("VAR_DEF is DEFINED")
else()
    message("VAR_NOT_DEF is NO DEFINED")
endif()

set(VAR1 123)
if(VAR1 EQUAL "123")
    message("VAR1 EQUAL 123")
endif()

set(VAR2 "test")
if(VAR2 EQUAL "test")
    message("VAR2 EQUAL test")
else()
    message("VAR2 NOT EQUAL test")
endif()

if(VAR2 STREQUAL "test")
    message("VAR2 STREQUAL test")
else()
    message("VAR2 NOT STREQUAL test")
endif()


if(VAR2 STREQUAL "test")
    message("VAR2 STREQUAL test")
else()
    message("VAR2 NOT STREQUAL test")
endif()

set(STR1 "abcd1234")
if(STR1 MATCHES "[a-z]+")
    message("abcd1234 MATCHES ^[a-z]+$")
else()
    message("abcd1234 NOT MATCHES ^[a-z]+$")
endif()

if(STR1 MATCHES "^[a-z]+$")
    message("abcd1234 MATCHES ^[a-z]+$")
else()
    message("abcd1234 NOT MATCHES ^[a-z]+$")
endif()