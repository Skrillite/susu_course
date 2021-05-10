#ifndef LAB_3_QUEUE_H
#define LAB_3_QUEUE_H

#include <iostream>
#include <concepts>
#include <vector>

namespace lab_3 {
    using namespace std;

    template<typename T>
    concept comparable = requires(T const & a, T const & b) {
        {a < b} -> convertible_to<bool>;
    };

    template <comparable Data>
    struct Node {
        Data data;
        Node* next_node;

        Node(int& _data, Node* _next_node)
                : next_node (_next_node)
                , data		(_data) {}
    };

    template <comparable Data>
    struct Queue {
        void push (Data data);
        Data pop  ();
        Data front();
        size_t size ();
        bool empty();

        Queue()
                : first	(nullptr)
                , last	(nullptr)
                , _size (0) {}
        Queue(vector<Data> vec)
                : _size(0)
                , first (nullptr)
                , last  (nullptr) {
            for (auto i : vec) this->push(i);
        };
    private:
        Node<Data>* first;
        Node<Data>* last;
        size_t _size{};
    };

    void task(Queue<int> q);
}
#endif //LAB_3_QUEUE_H
