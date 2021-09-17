#include "gtest/gtest.h"
#include "search.cpp"
#include "treap.cpp"
#include "boyer_moore.cpp"
#include <chrono>

namespace{
    using namespace std;
    using namespace chrono;
    using namespace search_by_str;
    using namespace search;
    using namespace treap;

    void task_1(int key, const vector<int>& vec) {
        for (auto i : vec) cout << i << ' ';
        cout << endl;

        int l(customLowerBound(key, vec)),
                r(customUpperBound(key, vec)),
                res(l == -1 || l == vec.size() ? 0 : r - l + 1);

        cout << "lower: " << l
             << " upper: " << r
             << " num: " << res << '\n';

        auto ub = upper_bound(vec.begin(), vec.end(), key);
        ub = ub == vec.end() ? ub : ub - 1;

        EXPECT_EQ(r - l,
                  ub - lower_bound(vec.begin(), vec.end(), key));
    }

    TEST(bin_search, task) {
        int num, key; cin >> num >> key;

        srand(high_resolution_clock::now()
                      .time_since_epoch().count());

        vector<int> vec(num);
        for (auto &i : vec)
            i = rand() % int(1e9);
        sort(vec.begin(), vec.end());

        task_1(key, vec);
    }

    TEST(bin_search, test) {
        vector<int> vec{0, 0, 1, 1, 1, 2, 3};

        task_1(1, vec);
    }

    TEST(bin_tree, task) {
        treap::Treap tr;

        for (auto i : {1, -1, 4, 3, 9, 5, 7})
            tr.add(i);

        tr.remove(3);

        tr.InorderTraversal(cout);
    }

    TEST(search_by_str, task) {
        string substr = "inquiry", path = R"(..\..\lab_6\input.txt)";
        cout << boyer_moore_search(substr, path);
    }
}