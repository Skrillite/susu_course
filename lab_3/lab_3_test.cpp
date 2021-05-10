#include "gtest/gtest.h"
#include "queue.h"

namespace lab_3 {

    TEST (queue, test_1) {

        EXPECT_EQ(task(Queue(vector<int>{10, 1, 1, 1, 0})).tovector(),
                  (vector<int>{10, 0}));

        EXPECT_EQ(task(Queue(vector<int>{-3, -10, 1, 2, 0})).tovector(),
                  (vector<int>{-3, -10, 2, 0}));
    }

    int main(int argc, char **argv) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }
}