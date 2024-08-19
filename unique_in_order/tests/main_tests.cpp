#include <gtest/gtest.h>
#include <random>
#include <algorithm>
#include "../src/UniqueInOrder.h"

TEST(UniqueInOrderTest, EmptyVectorInt) {
    std::vector<int> data = {};
    std::vector<int> result = uniqueInOrder(data);
    
    EXPECT_EQ(result.size(), 0);
}

TEST(UniqueInOrderTest, SingleElementVectorInt) {
    std::vector<int> data = {42};
    std::vector<int> result = uniqueInOrder(data);
    
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result, (std::vector<int>{42}));
}

TEST(UniqueInOrderTest, ConsecutiveDuplicatesVectorInt) {
    std::vector<int> data = {1, 1, 2, 2, 3, 3};
    std::vector<int> result = uniqueInOrder(data);

    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result, (std::vector<int>{1, 2, 3}));
}

TEST(UniqueInOrderTest, NoDuplicatesVectorInt) {
    std::vector<int> data = {1, 2, 3, 4, 5};
    std::vector<int> result = uniqueInOrder(data);

    EXPECT_EQ(result, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(UniqueInOrderTest, EmptyString) {
    std::string data = "";
    std::vector<char> result = uniqueInOrder(data);
    
    EXPECT_EQ(result.size(), 0);
}

TEST(UniqueInOrderTest, SingleElementString) {
    std::string data = "A";
    std::vector<char> result = uniqueInOrder(data);
    
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result, (std::vector<char>{'A'}));
}

TEST(UniqueInOrderTest, ConsecutiveDuplicatesString) {
    std::string data = "AAAABBBCCDAABBB";
    std::vector<char> result = uniqueInOrder(data);

    ASSERT_EQ(result.size(), 6);
    EXPECT_EQ(result, (std::vector<char>{'A', 'B', 'C', 'D', 'A', 'B'}));
}

TEST(UniqueInOrderTest, ConsecutiveDuplicatesLowerCaseString) {
    std::string data = "aaaabbbccdaabbb";
    std::vector<char> result = uniqueInOrder(data);

    ASSERT_EQ(result.size(), 6);
    EXPECT_EQ(result, (std::vector<char>{'a', 'b', 'c', 'd', 'a', 'b'}));
}

TEST(UniqueInOrderTest, ConsecutiveDuplicatesMixedCaseString) {
    std::string data = "ABBCcAD";
    std::vector<char> result = uniqueInOrder(data);

    ASSERT_EQ(result.size(), 6);
    EXPECT_EQ(result, (std::vector<char>{'A', 'B', 'C', 'c', 'A', 'D'}));
}

TEST(UniqueInOrderTest, NoDuplicatesString) {
    std::string data = "ABCDE";
    std::vector<char> result = uniqueInOrder(data);

    EXPECT_EQ(result, (std::vector<char>{'A', 'B', 'C', 'D', 'E'}));
}

TEST(UniqueInOrderTest, RandomIntVector) {
    std::vector<int> data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 10);

    for (int i = 0; i < 100; ++i) {
        data.push_back(distrib(gen));
    }

    std::vector<int> result = uniqueInOrder(data);

    std::vector<int> expected;
    for (size_t i = 0; i < data.size(); ++i) {
        if (i == 0 || data[i] != data[i - 1]) {
            expected.push_back(data[i]);
        }
    }

    EXPECT_EQ(result, expected);
}

TEST(UniqueInOrderTest, RandomString) {
    std::string data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 25);

    for (int i = 0; i < 100; ++i) {
        data.push_back('A' + distrib(gen));
    }

    std::vector<char> result = uniqueInOrder(data);

    std::vector<char> expected;
    for (size_t i = 0; i < data.size(); ++i) {
        if (i == 0 || data[i] != data[i - 1]) {
            expected.push_back(data[i]);
        }
    }

    EXPECT_EQ(result, expected);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}