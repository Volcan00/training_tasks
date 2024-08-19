
#include <gtest/gtest.h>
#include <random>
#include <algorithm>
#include "../src/Quicksort.h"

class QuicksortTest : public ::testing::Test {
protected:
    Quicksort sorter;
};

TEST_F(QuicksortTest, EmptyArray) {
    std::vector<int> data{};
    auto snapshots = sorter.quicksort(data);
    
    EXPECT_EQ(data.size(), 0);
    EXPECT_EQ(snapshots.size(), 0);
}

TEST_F(QuicksortTest, SingleElementArray) {
    std::vector<int> data{42};
    auto snapshots = sorter.quicksort(data);

    EXPECT_EQ(data.size(), 1);
    EXPECT_EQ(data[0], 42);
    EXPECT_EQ(snapshots.size(), 0);
}

TEST_F(QuicksortTest, AlreadySortedArray) {
    std::vector<int> data{1, 2, 3, 4, 5};
    auto snapshots = sorter.quicksort(data);

    EXPECT_EQ(data, (std::vector<int>{1, 2, 3, 4, 5}));
    EXPECT_GE(snapshots.size(), 0);

    if (!snapshots.empty()) {
        EXPECT_EQ(snapshots.back(), (std::vector<int>{1, 2, 3, 4, 5}));
    }
}

TEST_F(QuicksortTest, ReverseSortedArray) {
    std::vector<int> data{5, 4, 3, 2, 1};
    auto snapshots = sorter.quicksort(data);

    EXPECT_EQ(data, (std::vector<int>{1, 2, 3, 4, 5}));
    ASSERT_GT(snapshots.size(), 0);
    EXPECT_EQ(snapshots.back(), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST_F(QuicksortTest, UnsortedArray) {
    std::vector<int> data{3, 6, 8, 10, 1, 2, 1};
    auto snapshots = sorter.quicksort(data);

    EXPECT_EQ(data, (std::vector<int>{1, 1, 2, 3, 6, 8, 10}));
    ASSERT_GT(snapshots.size(), 0);
    EXPECT_EQ(snapshots.back(), (std::vector<int>{1, 1, 2, 3, 6, 8, 10}));
}

TEST_F(QuicksortTest, RandomArraySmall) {
    std::vector<int> data{5, 2, 9, 1, 5, 6};
    std::vector<int> expected(data);

    auto snapshots = sorter.quicksort(data);
    std::sort(expected.begin(), expected.end());

    EXPECT_EQ(data, expected);
}

TEST_F(QuicksortTest, RandomArrayLarge) {
    std::vector<int> data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 1000);

    for (int i = 0; i < 100; ++i) {
        data.push_back(distrib(gen));
    }

    std::vector<int> expected(data);
    auto snapshots = sorter.quicksort(data);
    std::sort(expected.begin(), expected.end());

    EXPECT_EQ(data, expected);
}

TEST_F(QuicksortTest, RandomArrayWithDuplicates) {
    std::vector<int> data{5, 2, 9, 1, 5, 6, 2, 9, 1};
    std::vector<int> expected(data);

    auto snapshots = sorter.quicksort(data);
    std::sort(expected.begin(), expected.end());

    EXPECT_EQ(data, expected);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}