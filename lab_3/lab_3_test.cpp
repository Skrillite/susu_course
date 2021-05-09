#include "gtest/gtest.h"
#include "queue.h"

namespace {
    using namespace lab_3;

    TEST (queue, test_1) {
        Queue q(vector<int>{10, 1, 1, 1, 1, 0});

        task(q);
        while (!q.empty()) cout << q.pop() << ' ';
        cout << '\n';
    }

    int main(int argc, char **argv) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }
}