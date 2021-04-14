
add_executable(task_2_tests task_2_tests.cpp linked_list.cpp)
target_link_libraries(task_2_tests
        PUBLIC gtest
        PUBLIC gtest_main)
