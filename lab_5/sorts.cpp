#include <vector>

namespace sorts {
    using namespace std;

    typedef vector<int>::iterator iter;
    void brokenMergeSort(iter begin, iter end) {
        if (begin + 1 >= end) return;

        auto mid = begin + (end - begin) / 2;

        brokenMergeSort(begin, mid);
        brokenMergeSort(mid, end);

        merge(begin, mid, end);
    }

    void merge(iter begin, iter mid, iter end) {
        auto it1 = begin,
            it2 = mid;
        vector<int> tmp(end - it1);
        while (it1 != mid && it2 != end) {
            if (*it1 < *it2) {
                tmp[(it1 - begin) + (it2 - mid)] = *it1;
                it1++;
            } else {
                tmp[(it1 - begin) + (it2 - mid)] = *it2;
                it2++;
            }
        }
    }
}

int main(){}