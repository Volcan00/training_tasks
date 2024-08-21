#include "../src/DigitalRoot.h"
#include <gtest/gtest.h>

// Test cases
TEST(DigitalRootTest, BasicCases) 
{
    // Testing simple cases
    int result {digitalRoot(5)};
    EXPECT_EQ(result, 5); // 5 is a single digit, so the digital root is 5

    result = digitalRoot(10);
    EXPECT_EQ(result, 1); // 1 + 0 = 1

    result = digitalRoot(38);
    EXPECT_EQ(result, 2); // 3 + 8 = 11, 1 + 1 = 2

    result = digitalRoot(123);
    EXPECT_EQ(result, 6); // 1 + 2 + 3 = 6

    result = digitalRoot(999);
    EXPECT_EQ(result, 9); // 9 + 9 + 9 = 27, 2 + 7 = 9
}

TEST(DigitalRootTest, LargeNumberCase) 
{
    // Testing a large number
    int result {digitalRoot(987654321)};
    EXPECT_EQ(result, 9); // Sum is 45, then 4 + 5 = 9
}

TEST(DigitalRootTest, EdgeCases) 
{
    // Testing edge cases
    int result {digitalRoot(0)};
    EXPECT_EQ(result, 0); // Digital root of 0 is 0

    result = digitalRoot(1);
    EXPECT_EQ(result, 1); // Digital root of 1 is 1

    result = digitalRoot(9);
    EXPECT_EQ(result, 9); // Digital root of 9 is 9
}

TEST(DigitalRootTest, RandomCases) 
{
    // Testing some random numbers
    int result {digitalRoot(456)};
    EXPECT_EQ(result, 6); // 4 + 5 + 6 = 15, 1 + 5 = 6

    result = digitalRoot(789);
    EXPECT_EQ(result, 6); // 7 + 8 + 9 = 24, 2 + 4 = 6

    result = digitalRoot(271828);
    EXPECT_EQ(result, 1); // 2 + 7 + 1 + 8 + 2 + 8 = 28, 2 + 8 = 10, 1 + 0 = 1

    result = digitalRoot(314159);
    EXPECT_EQ(result, 5); // 3 + 1 + 4 + 1 + 5 + 9 = 23, 2 + 3 = 5
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}