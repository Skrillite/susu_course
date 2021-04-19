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
    using namespace chrono;

    struct Node {
        Node* next{};

        int ap_num;
        int house_num;
        year_month_day date{};
        string name;
        string type_of_payment;

        Node(Node* next, int ap, int house, string name, year_month_day date, string payment)
            : ap_num(ap)
            , house_num(house)
            , name(move(name))
            , date(date)
            , type_of_payment(move(payment))
        {}
    };

    struct MergeSort {
        explicit MergeSort(function<bool(Node lhs, Node rhs)> predicate)
                : greaterThan(std::move(predicate)) {};

        Node* operator() (Node* begin, Node* end = nullptr) {
            return sort(begin);
        }

        Node* sort(Node* begin) {

            if (begin == nullptr || begin->next == nullptr) return begin;

            auto mid = split(begin);

            auto first = sort(begin);
            auto second = sort(mid);

            if (greaterThan(*first, *second)) swap(first, second);

            Node* res = first;
            while (first->next != nullptr && second != nullptr) {
                if (greaterThan(*(first->next), *second)) {
                    auto first_next  = first->next;
                    auto second_next = second->next;

                    first->next = second;
                    second->next = first_next;
                    first = second;
                    second = second_next;
                }
                else {
                    first = first->next;
                }
            }

            if (first->next == nullptr) first->next = second;

            return res;
        }

    private:
        function<bool(Node lhs, Node rhs)> greaterThan;

        Node* split(Node* begin) {
            Node* mid(begin), * cend(begin->next);

            char pc(1);
            while (cend->next) {
                cend = cend->next;
                if (++pc & 1) mid = mid->next;
            }

            auto md = mid->next;

            cend->next = nullptr;
            mid->next = nullptr;

            return md;
        }
    };

    struct LinkedList {
        Node* root{};

        void sortByHouse() {
            root = MergeSort([](const Node& lhs, const Node& rhs)->bool {
                return lhs.house_num > rhs.house_num;
            })(root, nullptr);
        }
        void sortByPayment() {
            root = MergeSort([](const Node& lhs, const Node& rhs) -> bool {
                return lhs.type_of_payment > rhs.type_of_payment;
            })(root, nullptr);
        }
        void sortByDate() {
            root = MergeSort([](const Node& lhs, const Node& rhs) -> bool {
                return lhs.date > rhs.date;
            })(root, nullptr);
        }

        Node* traversal(const function<bool(Node*)>& func) {
            auto curr = root;
            while (curr) {
                if (func(curr)) return curr;
                curr = curr->next;
            }
            return curr;
        }


        explicit LinkedList(size_t n) {
            srand(high_resolution_clock::now().time_since_epoch().count());

            if (n > 0) {
                root = new Node(
                        nullptr,
                        rand() % int(9e11) + int(1e11),
                        rand() % 99,
                        name_gen(rand() % 26 + 5),
                        year_month_day(
                                year(rand() % 42 + 1980),
                                month(rand() % 13),
                                day(rand() % 31)
                                ),
                        string_gen(rand() % 6 + 10, 'a', 'z')
                );
                auto curr = root;
                while (--n) {
                    curr->next = new Node(
                            nullptr,
                            rand() % int(9e11) + int(1e11),
                            rand() % 99,
                            name_gen(rand() % 26 + 5),
                            year_month_day(
                                    year(rand() % 42 + 1980),
                                    month(rand() % 13),
                                    day(rand() % 31)
                            ),
                            string_gen(rand() % 6 + 10, 'a', 'z')
                    );
                    curr = curr->next;
                }
            }
        }


        //  UTILS

        static string string_gen(int len, int first, int last) {
            string res;
            res.reserve(len);

            while (len--) res.push_back(first + (rand() % (last - first + 1)));

            return res;
        }

        static string name_gen(int len) {
            if (len > 0)
                return string_gen(1, 'A', 'Z') + string_gen(len - 1, 'a', 'z');
            return "";
        }
    };
}