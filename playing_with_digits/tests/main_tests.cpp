#include <gtest/gtest.h>
#include <ctime>
#include <cmath>
#include "../src/DigPow.h"

// Basic tests
TEST(DigPowTest, BasicTests)
{
    DigPow d {};

    EXPECT_EQ(d.digPow(89, 1), 1);
    EXPECT_EQ(d.digPow(695, 2), 2);
    EXPECT_EQ(d.digPow(46288, 3), 51);
    EXPECT_EQ(d.digPow(92, 1), -1);
    EXPECT_EQ(d.digPow(777, 1), -1);
    EXPECT_EQ(d.digPow(46288, 5), -1);
}

// Helper function for random tests
int generateRandomNumber(int min, int max)
{
    return min + std::rand() % ((max + 1) - min);
}

// Random tests
TEST(DigPowTest, RandomTest1)
{
    int n { generateRandomNumber(10, 99) }; // Two-digit number
    int p { generateRandomNumber(1, 5) };
    int result {  DigPow::digPow(n, p) };
    EXPECT_TRUE(result == -1 || (result > 0 && n * result == pow(n % 10, p) + pow((n / 10) % 10, p + 1)));
}

TEST(DigPowTest, RandomTest2)
{
    int n { generateRandomNumber(100, 999) }; // Three-digit number
    int p { generateRandomNumber(1, 5) };
    int result {  DigPow::digPow(n, p) };
    EXPECT_TRUE(result == -1 || (result > 0 && n * result == pow(n % 10, p) + pow((n / 10) % 10, p + 1) + pow((n / 100) % 10, p + 2)));
}

TEST(DigPowTest, RandomTest3)
{
    int n { generateRandomNumber(1000, 9999) }; // Four-digit number
    int p { generateRandomNumber(1, 5) };
    int result {  DigPow::digPow(n, p) };
    EXPECT_TRUE(result == -1 || (result > 0 && n * result == pow(n % 10, p) + pow((n / 10) % 10, p + 1) + pow((n / 100) % 10, p + 2) + pow((n / 1000) % 10, p + 3)));
}

TEST(DigPowTest, RandomTest4) {
    int n = generateRandomNumber(1, 100000);  // Random number up to 100000
    int p = generateRandomNumber(1, 5);
    int result = DigPow::digPow(n, p);
    EXPECT_TRUE(result == -1 || result > 0);
}

TEST(DigPowTest, RandomTest5) {
    int n = generateRandomNumber(1, 1000);  // Random number up to 1000
    int p = generateRandomNumber(1, 10);
    int result = DigPow::digPow(n, p);
    EXPECT_TRUE(result == -1 || result > 0);
}

TEST(DigPowTest, RandomTest6) {
    int n = generateRandomNumber(10, 999);  // Three-digit number
    int p = generateRandomNumber(5, 10);
    int result = DigPow::digPow(n, p);
    EXPECT_TRUE(result == -1 || result > 0);
}

TEST(DigPowTest, RandomTest7) {
    int n = generateRandomNumber(10000, 99999);  // Five-digit number
    int p = generateRandomNumber(1, 5);
    int result = DigPow::digPow(n, p);
    EXPECT_TRUE(result == -1 || result > 0);
}

TEST(DigPowTest, RandomTest8) {
    int n = generateRandomNumber(1000, 10000);  // Four-digit number
    int p = generateRandomNumber(1, 10);
    int result = DigPow::digPow(n, p);
    EXPECT_TRUE(result == -1 || result > 0);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}