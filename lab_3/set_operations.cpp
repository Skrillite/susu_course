#include <cmath>
#include <algorithm>
#include "set_operations.hpp"


namespace lab_3 {
    vector<int>& intersection(iter begin1, iter end1,
                             iter begin2, iter end2,
                             vector<int>& out) {

        while (begin1 != end1 && begin2 != end2) {
            if (*begin1 < *begin2) {
                begin1++;
            } else {
                if (*begin2 >= *begin1) out.push_back(*begin1++);
                begin2++;
            }
        }
        return out;
    }

    vector<int>& intersection(vector<pair<iter, iter>>& iters,
                              vector<int>& out) {
        while (all_of(iters.begin(), iters.end(),
                      [&](pair<iter, iter> i) {return i.first != i.second; })) {

            int max = -int(INFINITY);

            for (auto i : iters)
                if (*i.first > max) max = *i.first;

            bool push = true;
            for (auto &i : iters)
                if (*i.first != max) {
                    push = false;
                    i.first++;
                }

            if (push) {
                out.emplace_back(*iters[0].first);
                for (auto& i : iters) i.first++;
            }
        }
        return out;
    }

    vector<int>& sUnion(iter begin1, iter end1,
                       iter begin2, iter end2,
                       vector<int>& out) {

        while (begin1 != end1 && begin2 != end2) {
            if (*begin1 < *begin2) {
                out.push_back(*begin1++);
            } else {
                out.push_back(*begin2);
                if (*begin2 == *begin1) begin1++;
                begin2++;
            }
        }

        while (begin1 != end1) out.push_back(*begin1++);
        while (begin2 != end2) out.push_back(*begin2++);

        return out;
    }


    vector<int>& sUnion(vector<pair<iter, iter>> &iters,
                        vector<int>& out) {

        while (any_of(iters.begin(), iters.end(),
              [&](pair<iter, iter> i){return i.first != i.second;})) {

            int min = INFINITY;
            for (auto &i : iters)
                if (i.first != i.second && *i.first < min) min = *i.first;

            for (auto &i : iters)
                if (i.first != i.second && *i.first == min) i.first++;

            out.push_back(min);
        }

        return out;
    }

    vector<int>& diff(iter begin1, iter end1,
                      iter begin2, iter end2,
                      vector<int>& out) {

        while (begin1 != end1 && begin2 != end2) {
            if (*begin1 < *begin2) out.push_back(*begin1++);
            else if (*begin2 < *begin1) begin2++;
            else {
                begin1++; begin2++;
            }
        }

        while (begin1 != end1) out.push_back(*begin1++);

        return out;
    }
}