#include "queue.hpp"

namespace lab_3 {

    void Queue::push(int data) {
        if (!empty()) {
            first->next_node = new Node(data, nullptr);
            first = first->next_node;
        } else {
            first = last = new Node(data, nullptr);
        }
        _size++;
    }

    int Queue::pop() {
        if (!empty()) {
            Node *tmp = last;
            auto ret = last->data;

            last = last->next_node;
            delete tmp;
            _size--;

            return ret;
        }
        return 0;
    }

    int Queue::front() {
        if (!empty())
            return last->data;
        return 0;
    }

    bool Queue::empty() {
        return last == nullptr;
    }

    size_t Queue::size() const {
        return _size;
    }

    Queue::Queue(const vector<int>& vec)
            : _size (0)
            , first (nullptr)
            , last  (nullptr) {
        for (auto i : vec) this->push(i);
    }

    vector<int> Queue::tovector() {
        vector<int> ret; ret.reserve(size());

        auto curr = last;
        while (curr != nullptr) {
            ret.push_back(curr->data);
            curr = curr->next_node;
        }

        return ret;

    }
    Queue task(Queue q) {
        int min, max, minidx(q.size()), maxidx(minidx);

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

            if (abs(maxidx - minidx) > 1) {
                size = q.size();
                while (size--) {
                    auto val = q.pop();

                    if (val == min) {
                        q.push(val);
                        while (q.front() != max) {
                            size--;
                            q.pop();
                        }
                        size--;
                        q.push(q.pop());
                        continue;
                    }

                    else if (val == max) {
                        q.push(val);
                        while (q.front() != min) {
                            size--;
                            q.pop();
                        }
                        size--;
                        q.push(q.pop());
                        continue;
                    }

                    q.push(val);
                }
            }
        }
        return q;
    }
}
