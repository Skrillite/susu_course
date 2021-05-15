#include "set_operations.hpp"


namespace lab_3 {

    vector<int> task_a(vector<vector<int>>& t) {
        vector<pair<iter, iter>> iters; iters.reserve(t.size());
        vector<int> out; out.reserve(t[0].size());

        for (auto &i : t)
            iters.emplace_back(make_pair(i.begin(), i.end()));

        intersection(iters, out);

        return out;
    }

    vector<int> task_b(vector<vector<int>>& t) {
        vector<pair<iter, iter>> iters; iters.reserve(t.size());
        vector<int> out; out.reserve(t[0].size());

        for (auto &i : t)
            iters.emplace_back(make_pair(i.begin(), i.end()));

        sUnion(iters, out);

        return out;
    }

    vector<int> task_c(vector<vector<int>>& t, vector<int>& u){
        vector<pair<iter, iter>> iters; iters.reserve(t.size());
        vector<int> out; out.reserve(t[0].size());

        for (auto &i : t)
            iters.emplace_back(make_pair(i.begin(), i.end()));

        vector<int> dout; dout.reserve(u.size());
        diff(u.begin(), u.end(),
             sUnion(iters, out).begin(),
             out.end(), dout);

        return dout;
    }
}