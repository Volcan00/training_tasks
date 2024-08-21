#include "../src/Tortoise.h"
#include <gtest/gtest.h>

// Basic test case: Catch A with a smaller lead
TEST(TortoiseTest, BasicTest1) {
    std::vector<int> expected = {0, 32, 18};
    std::vector<int> result = Tortoise::race(720, 850, 70);
    EXPECT_EQ(result, expected);
}

// Basic test case: Catch A with a different set of speeds
TEST(TortoiseTest, BasicTest2) {
    std::vector<int> expected = {3, 21, 49};
    std::vector<int> result = Tortoise::race(80, 91, 37);
    EXPECT_EQ(result, expected);
}

// Edge case: B is slower than A, should never catch up
TEST(TortoiseTest, EdgeCase1) {
    std::vector<int> expected = {-1, -1, -1};
    std::vector<int> result = Tortoise::race(850, 720, 70);
    EXPECT_EQ(result, expected);
}

// Edge case: B has the same speed as A, should never catch up
TEST(TortoiseTest, EdgeCase2) {
    std::vector<int> expected = {-1, -1, -1};
    std::vector<int> result = Tortoise::race(720, 720, 100);
    EXPECT_EQ(result, expected);
}

// Random test case: B barely faster than A
TEST(TortoiseTest, RandomTest1) {
    std::vector<int> expected = {70, 0, 0}; // Adjust this based on actual calculated values
    std::vector<int> result = Tortoise::race(1000, 1001, 70);
    EXPECT_EQ(result, expected);
}

// Random test case: Small lead and slow speeds
TEST(TortoiseTest, RandomTest2) {
    std::vector<int> expected = {20, 0, 0}; // Adjust this based on actual calculated values
    std::vector<int> result = Tortoise::race(10, 15, 100);
    EXPECT_EQ(result, expected);
}

// Random test case: Large lead with close speeds
TEST(TortoiseTest, RandomTest3) {
    std::vector<int> expected = {1, 0, 0}; // Adjust this based on actual calculated values
    std::vector<int> result = Tortoise::race(1000, 1200, 200);
    EXPECT_EQ(result, expected);
}

// Random test case: Significant speed difference and lead
TEST(TortoiseTest, RandomTest4) {
    std::vector<int> expected = {0, 48, 0}; // Adjust this based on actual calculated values
    std::vector<int> result = Tortoise::race(500, 1000, 400);
    EXPECT_EQ(result, expected);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}