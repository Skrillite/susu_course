#include "queue.h"

namespace lab_3 {

    template<comparable Data>
    void Queue<Data>::push(Data data) {
        if (!empty()) {
            first->next_node = new Node<Data>(data, nullptr);
            first = first->next_node;
        } else {
            first = new Node<Data>(data, nullptr);
            last = first;
        }
        _size++;
    }

    template<comparable Data>
    Data Queue<Data>::pop() {
        if (!empty()) {
            Node<Data> *tmp = last;
            auto ret = last->data;

            last = last->next_node;
            delete tmp;
            _size--;

            return ret;
        }
    }

    template<comparable Data>
    Data Queue<Data>::front() {
        if (!empty())
            return last->data;
        return 0;
    }

    template<comparable Data>
    bool Queue<Data>::empty() {
        return last == nullptr;
    }

    template<comparable Data>
    size_t Queue<Data>::size() {
        return _size;
    }

//    template<comparable Data>
//    Queue<Data>::Queue(vector<Data> vec)
//            : _size(0) {
//        for (auto i : vec) this->push(i);
//    }

    void task(Queue<int> q) {
        int min, max;
        size_t minidx, maxidx;

        if (q.size() > 2) {
            min = max = q.front();

            auto size = q.size();
            while (size--) {
                auto val = q.pop();

                if (val < min) {
                    minidx = size;
                    min = val;
                }
                if (val > max) {
                    maxidx = size;
                    max = val;
                }
                q.push(val);
            }

            if (abs(min - max) > 1) {
                size = q.size();
                while (size--) {
                    auto val = q.pop();

                    if (val == min) while (q.pop() != max) size--;
                    else if (val == max) while (q.pop() != min) size--;
                }
            }
        }
    }
}