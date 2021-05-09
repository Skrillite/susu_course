#include <vector>

namespace sorts {
    using namespace std;

    typedef vector<int>::iterator iter;
    void brokenMerge(iter begin, iter mid, iter end) {
        vector<int> tmp(end - begin, 0);

        auto itl = begin, itr = mid, itt = tmp.begin();

        for (auto i = begin; i != end; i++)
            if (*i & 1) tmp[i - begin] = *i;

        while (itl != mid && (*itl & 1)) itl++;
        while (itr != end && (*itr & 1)) itr++;
        while (itt != tmp.end() && (*itt & 1)) itt++;

        while (itl != mid && itr != end) {
            if (*itl < *itr) {
                *itt = *itl;
                itl++; itt++;
            }
            else if (!(*itr & 1)) {
                *itt = *itr;
                itr++; itt++;
            }

            while (itl != mid && (*itl & 1)) itl++;
            while (itr != end && (*itr & 1)) itr++;
            while (itt != tmp.end() && (*itt & 1)) itt++;
        }

        while (itl != mid) {
            while (itt != tmp.end() && (*itt & 1)) itt++;

            if (!(*itl & 1)) {
                *itt = *itl;
                itt++;
            }
            itl++;
        }
        while (itr != end) {
            while (itt != tmp.end() && (*itt & 1)) itt++;

            if (!(*itr & 1)) {
                *itt = *itr;
                itt++;
            }
            itr++;
        }

        for (auto i = begin, j = tmp.begin(); i != end; i++, j++) *i = *j;
    }

    void brokenMergeSort(iter begin, iter end) {
        if (begin + 1 >= end) return;

        auto mid = begin + (end - begin) / 2;

        brokenMergeSort(begin, mid);
        brokenMergeSort(mid, end);

        brokenMerge(begin, mid, end);
    }

    void brokenInsertionSort(iter begin, iter end) {
        vector<int*> even; even.reserve((end - begin)/2);
        for (auto i = begin; i != end; i++)
            if (!(*i & 1)) even.push_back(&*i);

        for (auto i = even.begin(); i != even.end(); i++) {
                for (auto j = i; j != even.begin() && **(j - 1) > **j; j--)
                    swap (**j, **(j - 1));
        }
    }
}
