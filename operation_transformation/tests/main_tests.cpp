#include "../src/Transform.h"
#include <gtest/gtest.h>

// Basic tests for the operation function.
TEST(TransformTest, BasicCases) {
    // Test 1: Both a and b are the same.
    EXPECT_EQ(Transform::operation(1024, 1024), 0);

    // Test 2: a = 2, b = 8 (Expect 2 operations: 2 * 2 = 4, 4 * 2 = 8)
    EXPECT_EQ(Transform::operation(2, 8), 2);

    // Test 3: a = 9, b = 2 (Expect 2 operations: (9-1)/2 = 4, 4/2 = 2)
    EXPECT_EQ(Transform::operation(9, 2), 2);

    // Test 4: a = 16, b = 8 (Expect 1 operation: 16/2 = 8)
    EXPECT_EQ(Transform::operation(16, 8), 1);

    // Test 5: a = 15, b = 2 (Expect 4 operations: (15-1)/2 = 7, (7-1)/2 = 3, (3-1)/2 = 1, 1*2 = 2)
    EXPECT_EQ(Transform::operation(15, 2), 4);
}

// Randomized tests for the operation function.
TEST(TransformTest, RandomCases) {
    // Random test 1: a = 1000, b = 64 (Expect multiple operations, specific count determined by halving)
    EXPECT_EQ(Transform::operation(1000, 64), 15);

    // Random test 2: a = 500, b = 256 (Expect: 500 -> 250 -> 125 -> 62 -> 31 -> 15 -> 7 -> 3 -> 1 -> 2 -> 4 -> 8 -> 16 -> 32 -> 64 -> 128 -> 256)
    EXPECT_EQ(Transform::operation(500, 256), 16);

    // Random test 3: a = 777, b = 128
    EXPECT_EQ(Transform::operation(777, 128), 16);

    // Random test 4: a = 1, b = 1024 (Expect log2(1024) = 10 steps)
    EXPECT_EQ(Transform::operation(1, 1024), 10);

    // Random test 5: a = 10000, b = 32
    EXPECT_EQ(Transform::operation(10000, 32), 14);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}