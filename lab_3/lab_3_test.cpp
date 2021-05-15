#include "gtest/gtest.h"
#include "queue.hpp"
#include "set_operations.hpp"
#include "set_task.hpp"


namespace lab_3 {

    TEST (queue, test) {

        EXPECT_EQ(task(Queue(vector<int>{10, 1, 1, 1, 0})).tovector(),
                  (vector<int>{10, 0}));

        EXPECT_EQ(task(Queue(vector<int>{-3, -10, 1, 2, 0})).tovector(),
                  (vector<int>{-3, -10, 2, 0}));
    }

    TEST (set_oper, intersec_test) {
        vector<vector<int>> vecs {{1, 2, 3}, {1, 3, 5}};
        vector<int> out; out.reserve(vecs[0].size());

        vector<pair<iter, iter>> iters; iters.reserve(vecs.size());
        for (auto &i : vecs)
            iters.emplace_back(make_pair(i.begin(), i.end()));

        EXPECT_EQ(intersection(iters, out),
                  (vector<int> {1, 3}));
    }

    TEST (set_oper, union_test) {
        vector<vector<int>> vecs {{1, 2, 3, 6},
                                  {1, 3, 7, 8, 9, 11}};
        vector<int> out; out.reserve(vecs[0].size());

        vector<pair<iter, iter>> iters; iters.reserve(vecs.size());
        for (auto &i : vecs)
            iters.emplace_back(make_pair(i.begin(), i.end()));

        EXPECT_EQ(sUnion(iters, out),
                  (vector<int> {1, 2, 3, 6, 7, 8, 9, 11}));
    }


    TEST (set_oper, diff) {
        vector<int> a {1, 2, 3, 6};
        vector<int> b {1, 3, 7, 8, 9, 11};
        vector<int> out; out.reserve(a.size());

        diff(a.begin(), a.end(),
             b.begin(), b.end(),
             out);

        EXPECT_EQ(out, (vector<int> {2, 6}));
    }

    TEST(tasks, complete_test) {
        vector<vector<int>> t{
                {1, 2, 3},
                {2, 3, 5},
                {2, 3, 6},
                {1, 2, 3, 4},
                {2, 3},
                {2, 3, 4},
                {2, 3, 7},
                {2, 3, 8},
                {2, 3, 9},
                {1, 2, 3, 8},
                {2, 3, 6, 9},
        };

        vector<int> u {1, 2, 3, 4, 5, 6, 7, 8, 9};

        EXPECT_EQ(task_a(t), (vector<int> {2, 3}));
        EXPECT_EQ(task_b(t), u);
        EXPECT_EQ(task_c(t, u), (vector<int> {}));
    }

    int main(int argc, char **argv) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }
}