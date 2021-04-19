
namespace stack {
    struct Node {
        Node *next;
        int val;

        Node(Node *next, int val)
                : next(next), val(val) {};
    };

    struct Stack {
        Node *root;

        void add(int val) {
            root = new Node(root, val);
        }

        Node *pop_back() {
            auto ret = root;
            auto del = root;
            root = root->next;
            delete del;
            return ret;
        }

        int sum(int k) {
            int counter(0);
            auto curr = root;
            while (k--) {
                counter += curr->val;
                curr = curr->next;
            }
            return counter;
        }
    };
}

