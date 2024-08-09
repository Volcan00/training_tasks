#include <gtest/gtest.h>
#include <ctime>
#include "../src/TenMinuteWalk.h"

// Basic Tests
TEST(IsValidWalkTest, BasicTests)
{
    // Test a valid walk that returns to the start
    EXPECT_TRUE(isValidWalk({'n', 's', 'n', 's', 'n', 's', 'n', 's', 'e', 'w'}));

    // Test an invalid walk that doesn't return to the start
    EXPECT_FALSE(isValidWalk({'n', 'n', 'n', 's', 's', 's', 'e', 'e', 'e', 'w'}));

    // Test a walk with insufficient steps
    EXPECT_FALSE(isValidWalk({'n', 's', 'e', 'w'}));

    // Test a valid walk with mixed directions
    EXPECT_TRUE(isValidWalk({'n', 's', 'e', 'w', 'n', 's', 'e', 'w', 'n', 's'}));

    // Test an invalid walk that has the right number of steps but doesn't return to the start
    EXPECT_FALSE(isValidWalk({'n', 'n', 'e', 'w', 'n', 's', 'e', 'w', 'n', 's'}));
}

// Random Tests
TEST(IsValidWalkTest, RandomTests) {
    srand(static_cast<unsigned int>(time(nullptr)));

    // Test 1: Random valid walk
    std::vector<char> randomValidWalk(10);
    for(int i = 0; i < 5; ++i) {
        char dir = rand() % 2 == 0 ? 'n' : 'e';
        randomValidWalk[i] = dir;
        randomValidWalk[9 - i] = dir == 'n' ? 's' : 'w';
    }
    EXPECT_TRUE(isValidWalk(randomValidWalk));

    // Test 2: Completely random walk of 10 steps (unlikely to be valid)
    std::vector<char> randomWalk(10);
    char directions[] = {'n', 's', 'e', 'w'};
    for(int i = 0; i < 10; ++i) {
        randomWalk[i] = directions[rand() % 4];
    }
    std::cout << "Random walk: ";
    for(char dir : randomWalk) std::cout << dir << " ";
    std::cout << std::endl;
    // We can't predict the result, so no expectation is set here
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}