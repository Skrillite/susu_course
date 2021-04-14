#include <string>
#include <tuple>
#include <functional>
#include <utility>
#include <vector>
#include <ctime>
#include <random>
#include <chrono>

namespace lab_2 {
    using namespace std;

    struct Node {
        Node* next{};

        int ap_num;
        int house_num;
        year_month_day date{};
        string name;
        string type_of_payment;

        Node(Node* next, int ap, int house, string name, string payment)
            : ap_num(ap)
            , house_num(house)
            , name(std::move(name))
            , type_of_payment(std::move(payment))
        {}
    };

    struct MergeSort {
        explicit MergeSort(function<bool(Node lhs, Node rhs)> predicate)
            : greaterThan(std::move(predicate)) {} ;

        Node* operator() (Node* begin, Node* end) {
            sort(begin, end);
        }

        Node* sort(Node* begin, Node* end = nullptr) {

            if (begin == nullptr || begin->next == nullptr) return begin;

            auto mid = split(begin, end);

            auto first = sort(begin, mid);
            auto second = sort(mid, end);

            if (greaterThan(*first, *second)) swap(first, second);
            Node* res = first;

            while (first->next != mid && second != end) {
                if (greaterThan(*first->next, *second)) {
                    auto tmp = first->next;
                    auto tmp2 = second->next;

                    first->next = second;
                    second->next = tmp;
                    first = tmp;
                    second = tmp2;
                } else {
                    auto tmp = second->next;
                    second->next = first->next;
                    first->next = second;
                    second = tmp;
                }
            }

            if (first == mid) first->next = second;

            return res;
        }

    private:
        function<bool(Node lhs, Node rhs)> greaterThan;

        Node* split(Node* begin, Node* end) {
            Node* mid(begin), * cend(begin->next);

            char pc(0);
            while (cend->next != end) {
                cend = cend->next;
                if (++pc & 1) mid = mid->next;
            }

            return mid;
        }
    };

    struct LinkedList {
        Node* root{};

        void sortByHouse() {
            MergeSort sort([](const Node& lhs, const Node& rhs)->bool {
                return lhs.house_num > rhs.house_num;
            });
            sort.sort(root, nullptr);
        }

        LinkedList(size_t n) {
            srand(time(nullptr));

            auto curr = root;
            while(n-- > 0) {
                curr = new Node(
                        curr,
                        rand() % int(9e11) + int(1e11),
                        rand() % 99,
                        gen(rand() % 26 + 5),
                        gen(rand() % 6 + 10)
                );
            }
        }

        static string gen(int len) {
            string res;
            res.reserve(len);

            while (len-- > 0) {
                res.push_back(rand() % 58 + 65);
            }
        }
    };
}