#include "gtest/gtest.h"
#include "HashTable.cpp"
#include <fstream>

namespace hash {

    TEST(hashMap, task_1) {

        vector<pair<char, int>> alph; alph.reserve(26);
        for (auto i = 'a'; i <= 'z'; i++)
            alph.emplace_back(make_pair(i, 0));

        HashTable<pair<char, int>> table(alph);

        string input("aaaabbbbccccxxxxjhhggg");
        for (auto i : input) table[i]++;

        table.show(cout);
    }

    TEST(hashMap, task_2) {
        ifstream stream(R"(..\..\lab_4\task_2.txt)");
        string word;

        HashTable<string> table(10);

        if (stream.is_open())
            while (getline(stream, word, ' '))
                table.insert(word);
        else
            throw std::exception();

        cout << table["others"] << '\n';

        cout << table.collisionCount() << '\n';
    }

    int main(int argc, char **argv) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }
}
