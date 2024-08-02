#include <gtest/gtest.h>
#include <cstdlib>
#include <ctime>
#include "./src/Functions.h"

TEST(EulersTotientFunctionTest, BasicTests)
{
    EXPECT_EQ(eulersTotientFunction(1), 1);
    EXPECT_EQ(eulersTotientFunction(2), 1);
    EXPECT_EQ(eulersTotientFunction(3), 2);
    EXPECT_EQ(eulersTotientFunction(4), 2);
    EXPECT_EQ(eulersTotientFunction(5), 4);
    EXPECT_EQ(eulersTotientFunction(6), 2);
    EXPECT_EQ(eulersTotientFunction(7), 6);
    EXPECT_EQ(eulersTotientFunction(8), 4);
    EXPECT_EQ(eulersTotientFunction(9), 6);
    EXPECT_EQ(eulersTotientFunction(10), 4);
    EXPECT_EQ(eulersTotientFunction(12), 4);
    EXPECT_EQ(eulersTotientFunction(13), 12);
    EXPECT_EQ(eulersTotientFunction(17), 16);
    EXPECT_EQ(eulersTotientFunction(18), 6);
    EXPECT_EQ(eulersTotientFunction(19), 18);
    EXPECT_EQ(eulersTotientFunction(20), 8);
    EXPECT_EQ(eulersTotientFunction(25), 20);
    EXPECT_EQ(eulersTotientFunction(100), 40);
    EXPECT_EQ(eulersTotientFunction(1000), 400);
}

TEST(EulersTotientFunctionTest, RandomTests)
{
    std::srand(std::time(nullptr));

    for(int i = 0; i < 100; ++i)
    {
        int n {std::rand() % 1000 + 1};
        int result {eulersTotientFunction(n) };

        EXPECT_GE(result, 1);
        EXPECT_LE(result, 1000);
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}