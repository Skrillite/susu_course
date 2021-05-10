#ifndef LAB_3_QUEUE_H
#define LAB_3_QUEUE_H

#include <iostream>
#include <concepts>
#include <vector>

namespace lab_3 {
    using namespace std;

    struct Node {
        int data;
        Node* next_node;

        Node(int& _data, Node* _next_node)
                : next_node (_next_node)
                , data		(_data) {}
    };

    struct Queue {
        void push (int data);
        int pop  ();
        int front();
        size_t size () const;
        bool empty();

        vector<int> tovector();

        Queue()
                : first	(nullptr)
                , last	(nullptr)
                , _size (0) {}
        explicit Queue(const vector<int>& vec);
    private:
        Node* first;
        Node* last;
        size_t _size{};
    };

    Queue task(Queue q);
}
#endif //LAB_3_QUEUE_H
