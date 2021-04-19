cmake_minimum_required(VERSION 3.17)
project(lab_1)

set(CMAKE_CXX_STANDARD 20)
#find_path(tmp g++.exe ENV{Path})
#set(CMAKE_CXX_COMPILER ${tmp}/g++.exe)

add_subdirectory(${CMAKE_SOURCE_DIR}/googletest)

add_subdirectory(${CMAKE_SOURCE_DIR}/lab_1)
add_subdirectory(${CMAKE_SOURCE_DIR}/lab_2)

if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    add_compile_options(
            /W4
    )
else ()
    add_compile_options(
            -std=c++20
    )
endif()
