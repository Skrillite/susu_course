#include "gtest/gtest.h"
#include "linked_list.cpp"

TEST (split_test, test_1) {
    int n = 15;
    while(n-- > 0)
        std::cout << lab_2::LinkedList::gen(10) << std::endl;
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}