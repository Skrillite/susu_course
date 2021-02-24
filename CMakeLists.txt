cmake_minimum_required(VERSION 3.17)
project(task_1)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(${CMAKE_SOURCE_DIR}/googletest)
add_subdirectory(${CMAKE_SOURCE_DIR}/task_1)

if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

#    target_compile_options(
#            test_exec PRIVATE
#            /W4
#    )
else ()
#    target_compile_options(
#            test_exec PRIVATE
#            -Wall -Wextra -pedantic -Werror
#    )
endif()
