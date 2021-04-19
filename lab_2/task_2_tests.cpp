#include "gtest/gtest.h"
#include "linked_list.cpp"
#include "stack.cpp"

namespace {

    using namespace lab_2;

    ostream& operator<<(ostream& stream, const year_month_day& date) {
        return cout << date.day().operator unsigned int()
                    << '.' << date.month().operator unsigned int()
                    << '.' << date.year().operator int();
    }

    TEST (split_test, gen_test_1) {
        int n = 15;
        while (n-- > 0)
            cout << int(LinkedList::string_gen(1, 'A', 'Z')[0]) << '\n';
    }

    TEST (linked_list, sort_by_date) {
        auto list = LinkedList(10);

        auto curr = list.root;
        while (curr) {
            cout << curr->date << '\n';
            curr = curr->next;
        }
        cout << '\n';

        list.sortByDate();
        curr = list.root;
        while (curr != nullptr) {
            cout << curr->date << '\n';
            curr = curr->next;
        }
    }

    TEST (linked_list, sort_by_payment) {
        auto list = LinkedList(10);

        auto curr = list.root;
        while (curr) {
            cout << curr->type_of_payment << '\n';
            curr = curr->next;
        }
        cout << '\n';

        list.sortByPayment();
        curr = list.root;
        while (curr) {
            cout << curr->type_of_payment << '\n';
            curr = curr->next;
        }
    }
    TEST (linked_list, sort_by_house) {
        auto list = LinkedList(10);

        auto curr = list.root;
        while (curr) {
            cout << curr->house_num << ' ';
            curr = curr->next;
        }
        cout << '\n';

        list.sortByHouse();
        curr = list.root;
        while (curr) {
            cout << curr->house_num << ' ';
            curr = curr->next;
        }
    }

    TEST(linked_list, search) {
        auto list = LinkedList(10);
        auto answer_1 = list.root->next->next;
        auto answer_2 = list.root->next->next->next;

        auto test_1 = answer_1->type_of_payment;
        auto test_2 = answer_2->date;


        EXPECT_EQ(list.traversal([test_1](Node* lhs){
            return lhs->type_of_payment == test_1;
        })->house_num, answer_1->house_num);

        EXPECT_EQ(list.traversal([test_2](Node* lhs){
            return lhs->date == test_2;
        })->name, answer_2->name);
    }

    TEST(stack, task) {
        stack::Stack stack{};
        int qel = 10;
        vector<int> prefix;
        prefix.reserve(qel);

        while(qel--) {
            int val = rand() % 20;
            prefix.push_back(val);
            stack.add(val);
        }

        int counter(0);
        for (int i = 1; i <= prefix.size(); i++) {
            counter+= prefix[prefix.size() - i];
            EXPECT_EQ(stack.sum(i), counter);
        }
    }

    int main(int argc, char **argv) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }
}