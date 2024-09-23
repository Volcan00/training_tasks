#include "../src/SumDigPow.h"
#include <gtest/gtest.h>

// Basic test cases
TEST(SumDigPowTest, BasicCases) {
    // Testing a range with known Eureka numbers
    EXPECT_EQ(sumDigPow(1, 10), std::vector<unsigned int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
    
    // Testing a range that has one Eureka number (89)
    EXPECT_EQ(sumDigPow(10, 100), std::vector<unsigned int>({89}));

    // Testing a range that includes no Eureka numbers
    EXPECT_EQ(sumDigPow(100, 200), std::vector<unsigned int>({135, 175}));
    
    // Testing a range that includes larger Eureka numbers (135 and 175)
    EXPECT_EQ(sumDigPow(90, 200), std::vector<unsigned int>({135, 175}));
}

TEST(SumDigPowTest, SingleNumberRange) {
    // Testing when a and b are the same, and the number is a Eureka number
    EXPECT_EQ(sumDigPow(89, 89), std::vector<unsigned int>({89}));
    
    // Testing when a and b are the same, but the number is not a Eureka number
    EXPECT_EQ(sumDigPow(50, 50), std::vector<unsigned int>({}));
}

TEST(SumDigPowTest, EdgeCases) {
    // Test with minimal range (a == b and both are 1)
    EXPECT_EQ(sumDigPow(1, 1), std::vector<unsigned int>({1}));

    // Test with range where all numbers are less than 10
    EXPECT_EQ(sumDigPow(1, 9), std::vector<unsigned int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));

    // Test when the start of the range is higher than the end
    EXPECT_EQ(sumDigPow(100, 90), std::vector<unsigned int>({}));
    
    // Test with a large range, but no Eureka numbers in between
    EXPECT_EQ(sumDigPow(1000, 1050), std::vector<unsigned int>({}));
}

TEST(SumDigPowTest, RandomCases) {
    // Test a range that includes multiple Eureka numbers
    EXPECT_EQ(sumDigPow(1, 200), std::vector<unsigned int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 89, 135, 175}));
    
    // Test a large range where we expect no Eureka numbers
    EXPECT_EQ(sumDigPow(500, 600), std::vector<unsigned int>({518, 598}));
    
    // Test a large range, including 89, 135, 175, 518
    EXPECT_EQ(sumDigPow(80, 600), std::vector<unsigned int>({89, 135, 175, 518, 598}));
    
    // Test a range that includes 370, 371, and 407 (known Eureka numbers)
    EXPECT_EQ(sumDigPow(300, 500), std::vector<unsigned int>({}));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}