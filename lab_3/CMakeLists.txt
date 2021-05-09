
add_executable(lab_3 lab_3_test.cpp
        queue.cpp
        queue.h)
target_link_libraries(lab_3
        PUBLIC gtest
        PUBLIC gtest_main)
