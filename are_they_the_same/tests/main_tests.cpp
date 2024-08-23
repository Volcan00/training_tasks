#include "../src/Same.h"
#include <gtest/gtest.h>

// Test cases
TEST(SameCompTest, BasicTests) {
    std::vector<int> a1 {2, 3, 4};
    std::vector<int> b1 {4, 9, 16};
    EXPECT_TRUE(Same::comp(a1, b1));

    std::vector<int> a2 {1, 2, 3};
    std::vector<int> b2 {1, 4, 9};
    EXPECT_TRUE(Same::comp(a2, b2));

    std::vector<int> a3 {0, 0, 0};
    std::vector<int> b3 {0, 0, 0};
    EXPECT_TRUE(Same::comp(a3, b3));

    std::vector<int> a4 {2, 2};
    std::vector<int> b4 {4, 4};
    EXPECT_TRUE(Same::comp(a4, b4));
}

TEST(SameCompTest, RandomTests) {
    std::vector<int> a1 {1, 2, 3, 4};
    std::vector<int> b1 {1, 4, 9, 16};
    EXPECT_TRUE(Same::comp(a1, b1));

    std::vector<int> a2 {5, 6, 7};
    std::vector<int> b2 {25, 36, 49};
    EXPECT_TRUE(Same::comp(a2, b2));

    std::vector<int> a3 {0, 1, 2, 3};
    std::vector<int> b3 {0, 1, 4, 9};
    EXPECT_TRUE(Same::comp(a3, b3));

    std::vector<int> a4 {10, 11, 12};
    std::vector<int> b4 {100, 121, 144};
    EXPECT_TRUE(Same::comp(a4, b4));

    std::vector<int> a5 {1, 2, 3, 4};
    std::vector<int> b5 {1, 4, 16, 9}; // Unscrambled
    EXPECT_TRUE(Same::comp(a5, b5));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}