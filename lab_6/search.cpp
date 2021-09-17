#include <vector>

namespace search {
    using namespace std;

    int customLowerBound(int key, const vector<int> &vec) {
        int l = -1, r = vec.size();

        while (l < r - 1) {
            auto mid = l + (r - l) / 2;
            if (vec[mid] < key) l = mid;
            else r = mid;
        }

        return min(r, int(vec.size() - 1));
    }

    int customUpperBound(int key, const vector<int> &vec) {
        int l = -1, r = vec.size();

        while (l < r - 1) {
            auto mid = l + (r - l) / 2;
            if (key < vec[mid]) r = mid;
            else l = mid;
        }

        return l;
    }
}