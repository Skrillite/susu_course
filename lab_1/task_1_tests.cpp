#include "gtest/gtest.h"
#include "task_1.cpp"
#include <string>

TEST(d2h_test, test_1) {
    std::string input ("123");

    EXPECT_STRCASEEQ(std_dec2hex(input).c_str(), dec2hex(input).c_str());
}

TEST(d2h_test, test_2) {
    std::string input ("1");

    EXPECT_STRCASEEQ(std_dec2hex(input).c_str(), dec2hex(input).c_str());
}
TEST(d2h_test, test_3) {
    std::string input ("90824");

    EXPECT_STRCASEEQ(std_dec2hex(input).c_str(), dec2hex(input).c_str());
}
TEST(d2h_test, test_4) {
    std::string input ("0");

    EXPECT_STRCASEEQ(std_dec2hex(input).c_str(), dec2hex(input).c_str());
}

TEST(array_test, test_1) {
    std::vector<int> in {1, 2, 3, 4, 5}
    , out {1, 3, 5};

    EXPECT_EQ(arr(in), out);
}

TEST(array_test, test_2) {
    std::vector<int> in {2, 2, 2, 2}
    , out {};

    EXPECT_EQ(arr(in), out);
}

TEST(array_test, test_3) {
    std::vector<int> in {1, 1, 1, 1}
    , out {1, 1, 1, 1};

    EXPECT_EQ(arr(in), out);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
