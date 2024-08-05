#include <gtest/gtest.h>
#include <ctime>
#include "../src/ArrayHash.h"
#include "../src/Redistribution.h"

TEST(RedistributionTest, BasicTest)
{
    EXPECT_EQ(mem_alloc({0, 2, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}), 42);
    EXPECT_EQ(mem_alloc({5, 1, 10, 0, 1, 7, 13, 14, 3, 12, 8, 10, 7, 12, 0, 600}), 70);
    EXPECT_EQ(mem_alloc({53, 21, 10, 0, 1, 7, 13, 14, 3, 12, 8, 10, 7, 12, 0, 60}), 316);
    EXPECT_EQ(mem_alloc({14, 21, 10, 0, 1, 7, 0, 14, 3, 12, 8, 10, 17, 12, 0, 19}), 826);
    EXPECT_EQ(mem_alloc({5, 1, 10, 0, 1, 7, 13, 14, 3, 12, 8, 10, 7, 12, 0, 6}), 5042);
    EXPECT_EQ(mem_alloc({17, 17, 3, 5, 1, 10, 6, 2, 0, 12, 8, 11, 16, 2, 1, 6}), 158378);
}

TEST(RedistributionTest, RandomTest)
{
    std::srand(std::time(nullptr));

    for(int i = 0; i < 10; ++i)
    {
        std::array<unsigned int, 16> banks {};
        for(unsigned int &block : banks)
        {
            block = std::rand() % 10;
        }

        int cycles = mem_alloc(banks);

        EXPECT_GE(cycles, 0);
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}