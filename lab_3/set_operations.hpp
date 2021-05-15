#ifndef LABS_SET_OPERATIONS_HPP
#define LABS_SET_OPERATIONS_HPP

#include <vector>

namespace lab_3 {
    using namespace std;

    typedef vector<int>::iterator iter;

    vector<int>& intersection(vector<pair<iter, iter>> &iters,
                              vector<int>& out);

    vector<int>& sUnion(vector<pair<iter, iter>> &iters,
                        vector<int>& out);

    vector<int>& diff(iter begin1, iter end1,
                      iter begin2, iter end2,
                      vector<int>& out);
}

#endif //LABS_SET_OPERATIONS_HPP
