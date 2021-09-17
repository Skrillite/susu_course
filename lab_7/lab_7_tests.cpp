#include "gtest/gtest.h"
#include "deque.cpp"
#include <vector>

namespace lab_7 {
    TEST(deque, test_1) {
        Deque base;

        for (auto i : vector<int>{1, -1, 2, -2, 3, -3}) base.insert(i);

        auto a = base.split();
        a.first->traversal(cout);
        a.second->traversal(cout);
    }

    int main(int argc, char **argv) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }
}