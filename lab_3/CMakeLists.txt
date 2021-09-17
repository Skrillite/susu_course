
add_executable(lab_3 lab_3_test.cpp set_task.cpp)

add_library(set_operations
        set_operations.cpp
        set_operations.hpp)

add_library(queue
        queue.cpp
        queue.hpp)

target_link_libraries(lab_3
        PRIVATE queue
        PRIVATE set_operations
        PUBLIC gtest
        PUBLIC gtest_main)
