#include "gtest/gtest.h"
#include "sorts.cpp"
#include <chrono>
#include <algorithm>

namespace {
    using namespace sorts;

    void brokenSTDSort(vector<int> &input) {
        vector<int> even;

        for (auto i : input)
            if (!(i & 1)) even.push_back(i);

        sort(even.begin(), even.end());

        for (auto i = input.begin(), j = even.begin();
            i != input.end();
            i++
        )
            if (!(*i & 1)) {
                *i = *j;
                j++;
            }
    }

    TEST(mergeSort, demo) {
        vector<int> vec1 {1, 6, 3, -4, 9, 2}, vec2(vec1);

        brokenMergeSort(vec1.begin(), vec1.end());
        brokenSTDSort(vec2);

        EXPECT_EQ(vec1, vec2);
    }

    TEST(mergeSort, rand_tests) {
        using namespace chrono;
        srand(high_resolution_clock::now()
            .time_since_epoch().count());

        int q = 100;
        while (q--) {
            int size = rand() % 1001 + 500;
            vector<int> vec1(size);
            for (auto &i : vec1) i = rand() % int(1e9);

            vector<int> vec2(vec1);

            brokenMergeSort(vec1.begin(), vec1.end());
            brokenSTDSort(vec2);

            EXPECT_EQ(vec1, vec2);
        }
    }

    int main(int argc, char **argv) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }
}