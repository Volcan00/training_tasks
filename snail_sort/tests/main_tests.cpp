#include "../src/SnailSort.h"
#include <gtest/gtest.h>

TEST(SnailSortTest, Basic3x3Matrix) {
    std::vector<std::vector<int>> matrix {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::vector<int> expected {1, 2, 3, 6, 9, 8, 7, 4, 5};
    EXPECT_EQ(snailSort(matrix), expected);
}

TEST(SnailSortTest, Basic4x4Matrix) {
    std::vector<std::vector<int>> matrix {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    std::vector<int> expected {1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10};
    EXPECT_EQ(snailSort(matrix), expected);
}

TEST(SnailSortTest, EmptyMatrix) {
    std::vector<std::vector<int>> matrix {};
    std::vector<int> expected {};
    EXPECT_EQ(snailSort(matrix), expected);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}