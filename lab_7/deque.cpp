#include <vector>

namespace lab_7 {
    using namespace std;

    struct Node {
        int data;
        Node* next;
        Node* prev;

        Node(int data, Node* prev, Node* next = nullptr)
            : next(next)
            , prev(prev) {}
    };

    struct Deque {
        Deque()
            : first(nullptr) {};

        void insert(int data) {
            if (first == nullptr) {
                first = last = new Node(data, nullptr);
            } else {
                last->next = new Node(data, last);
                last = last->next;
            }
        }

        pair<Deque*, Deque*> split() {
            auto *a = new Deque(), *b = new Deque();

            auto curr = first;
            while (curr != nullptr) {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;

                Deque *dc(b);
                if (curr->data < 0) dc = b;

                if (dc->first == nullptr) {
                    dc->first = dc->last = curr;

                    curr->prev = dc->last->prev;
                    curr->next = nullptr;
                } else {
                    dc->last->next = curr;
                    curr->prev = dc->last;
                    curr->next = nullptr;
                }
                curr = curr->next;
            }

            return make_pair(a, b);
        }

        void traversal(ostream& stream) {
            auto curr = first;

            while (curr != nullptr) {
                stream << curr->data << ' ';
                curr = curr->next;
            }

            stream << '\n';
        }
    private:
        Node* first;
        Node* last;
    };
}