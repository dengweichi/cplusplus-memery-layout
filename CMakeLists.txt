cmake_minimum_required(VERSION 3.16)
project(cplusplus-memory-layout-learn)

set(CMAKE_CXX_STANDARD 14)
set(googleTestDir ./googletest)
add_subdirectory(${googleTestDir})
include_directories(${googleTestDir}/googletest/include)
include_directories(${googleTestDir}/googlemock/include)


#只支持x86-64位处理器
# 在windows操作系统下只支持msvc编译器 并且定义了一个 WIN_MSVC的宏
# 在linux系统下支持吃gnu的编译套件 并且定义了一个 LINUX_GNU的宏
if( (NOT(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "AMD64")) AND (NOT(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_64")))
    message(FATAL_ERROR "only support x86-64")
endif()

if (CMAKE_SYSTEM_NAME MATCHES "Windows")
    # windows只能使用msvc
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
        if(CMAKE_SIZEOF_VOID_P EQUAL 8)
            add_definitions(-DWIN_64_MSVC)
        else()
            add_definitions(-DWIN_32_MSVC)
        endif()
    elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        if(CMAKE_SIZEOF_VOID_P EQUAL 8)
            add_definitions(-DWIN_64_GNU)
        endif()
    else()
        message(FATAL_ERROR "windows system only support msvc compiler and gnu")
    endif()
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
    # linux只支持使用 gun的编译套件
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        if(CMAKE_SIZEOF_VOID_P EQUAL 8)
            add_definitions(-DLINUX_64_GNU)
        endif()
    else()
        message(FATAL_ERROR "linux system only support gun compiler")
    endif()
else()
    message(FATAL_ERROR "only support windows and linux")
endif ()


add_executable(${PROJECT_NAME} main.cpp ./test/test_stack_byte_align.cpp ./test/test_struct_byte_align.cpp ./test/test_class_byte_align.cpp)

target_link_libraries(${PROJECT_NAME} gtest gtest_main)
target_link_libraries(${PROJECT_NAME} gmock gmock_main)