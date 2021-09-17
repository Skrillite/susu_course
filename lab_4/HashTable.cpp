#include <string>
#include <vector>
#include <functional>
#include <chrono>

namespace hash {
    using namespace std;
    using namespace chrono;

    const size_t hashTableSize = 1e5;
    int mul[] = {2293, 1999, 3527, 3463, 3571, 1553, 2887, 2687, 3469, 4759};

    template <class T>
    struct Node {
        Node() = default;

        explicit Node(T data, Node *node = nullptr)
                : data(move(data)), nextNode(node) {}

        T data;
        Node *nextNode{};
    };

    template <class T>
    struct HashTable {
        HashTable(size_t size)
                : size(size)
                , table(new Node<T> *[size]{nullptr}) {}

        //perfect hashing
        HashTable (const vector<pair<char, int>>& data)
                : size(data.size() * data.size())
                , table(new Node<T> *[data.size() * data.size()]{nullptr}) {
            srand(high_resolution_clock::now().time_since_epoch().count());

            p = 6959, m = size;

            size_t changeHfCounter(0);

            bool complete(false);
            while (!complete) {
                randWeight();
                complete = true;

                for (auto i : data) {
                    int hash;
                    if (table[hash = hashFunction(i.first)] != nullptr) {
                        cleanTable();
                        complete = false;
                        changeHfCounter++;
                        break;
                    } else
                        table[hash] = new Node<T>(i);
                }
            }

            cout << changeHfCounter << " hash func changes\n";
        }

        void cleanTable() {
            auto s = size;
            while (s--)
                if (table[s] != nullptr) {
                    delete table[s];
                    table[s] = nullptr;
                }
        }

        void show(ostream& stream) {
            for (auto i = 0; i < size; i++)
                if (table[i] != nullptr)
                    stream << table[i]->data.first << ' '
                            << table[i]->data.second << '\n';
        }

        int hashFunction(int x) const {
            return (((a * x + b) % p) % m);
        }

        void randWeight() {
            a = rand() % p;
            b = rand() % p;
        }

        int& operator[](char x) {
            int hash;
            if (table[hash = hashFunction(x)] != nullptr)
                return table[hash]->data.second;
        }

        string& operator[](const string& x) {
            int hash;
            if (table[hash = hashFunction(x)] != nullptr) {
                auto curr = table[hash];

                while (curr != nullptr) {
                    if (curr->data == x) return curr->data;

                    curr = curr->nextNode;
                }
            }
        }

        int hashFunction(string str) {
            size_t ret(1);
            for (int i = 0; i < str.size(); i++)
                ret = str[i] + ret * mul[i];
            return ret % size;
        }

        void insert(const std::string &str) {
            auto hash = hashFunction(str);

            if (table[hash] != nullptr) {
                auto curr = table[hash];
                while (curr->nextNode != nullptr and curr->data != str) curr = curr->nextNode;

                if (curr-> data == str) return;

                curr->nextNode = new Node(str);
            } else
                table[hash] = new Node(str);
        }

        void erase(const std::string &str) {
            auto hash = hashFunction(str);
            if (table[hash] != nullptr && table[hash]->data != str) {

                auto curr = table[hash];
                while (curr->nextNode != nullptr || curr->data != str)
                    curr = curr->nextNode;

                if (curr->data != str) return;
            }
            delete table[hash];
            table[hash] = nullptr;
        }

        bool check(const std::string &str) {
            auto hash = hashFunction(str);

            if (table[hash] == nullptr) return false;
            else if (table[hash]->data != str) {

                auto curr = table[hash];
                while (curr->nextNode != nullptr || curr->data != str)
                    curr = curr->nextNode;

                if (curr->data != str) return false;
            }
            return true;
        }

        int collisionCount() {
            int gcounter(0);

            for (auto i = 0; i < size; i++) {
                if (table[i] != nullptr) {
                    int counter(0);

                    auto curr = table[i];
                    while (curr != nullptr){
                        counter++;
                        curr = curr->nextNode;
                    }

                    while (--counter) gcounter += counter;
                }
            }

            return gcounter;
        }

    private:
        Node<T> **table;
        size_t size{hashTableSize};
        int64_t a{}, b{}, p{}, m{};
    };
    

}