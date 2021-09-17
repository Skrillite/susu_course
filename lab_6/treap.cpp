#include <vector>

namespace treap {
    using namespace std;

    struct Node {
        Node(int _data, int _priority, Node *_parent = nullptr,
             Node *_left = nullptr, Node *_right = nullptr)
                : data(_data), priority(_priority), left(_left), right(_right), parent(_parent) {}

        friend class Treap;

        int data;
        int priority;
        Node *parent;
        Node *left;
        Node *right;
    };


    struct Treap {
        Treap()
                : root(nullptr) {};

        void merge(Node *L, Node *R) {
            merge(L, R, this->root);
        }

        void merge(Node *L, Node *R, Node *&root) {
            if (L == nullptr) {
                root = R;
                return;
            } else if (R == nullptr) {
                root = L;
                return;
            } else if (L->priority > R->priority) {
                root = L;
                merge(L->right, R, root->right);
            } else {
                root = R;
                merge(L, R->left, root->left);
            }
        }

        void split(int x, Node *&L, Node *&R) {
            split(x, L, R, this->root);
        }

        void split(int x, Node *&L, Node *&R, Node *root) {
            if (root == nullptr) {
                R = nullptr;
                L = nullptr;
                return;
            }
            if (root->data < x) {
                L = root;
                split(x, L->right, R, root->right);
            } else {
                R = root;
                split(x, L, R->left, root->left);
            }
        }

        void InorderTraversal(ostream &stream) {
            InorderTraversal(root, stream);
        }

        void InorderTraversal(Node *root, ostream &stream) {
            if (root != nullptr) {
                InorderTraversal(root->left, stream);
                stream << root->data << ' ';
                InorderTraversal(root->right, stream);
            }
        }

        void add(int key) {
            Node *L, *R, *new_node(new Node(key, rand()));

            split(key, L, R);
            merge(L, new_node, L);
            merge(L, R);
        }

        void remove(int key) {
            Node *L, *R, *removed;

            split(key, L, R);
            split(key + 1, removed, R, R);

            merge(L, R);
        }

    private:
        Node *root;
    };
}
