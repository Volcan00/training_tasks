#include "../src/FindOddNum.h"
#include <gtest/gtest.h>

// Test case 1: Single odd number with the rest even occurrence
TEST(FindOddTest, SingleOddNumber) {
    std::vector<int> numbers {1, 2, 2, 1, 1};
    EXPECT_EQ(findOdd(numbers), 1);
}

// Test case 2: All numbers have even occurrences
TEST(FindOddTest, NoOddOccurrences) {
    std::vector<int> numbers {1, 2, 2, 1};
    EXPECT_EQ(findOdd(numbers), 0);  // No odd occurrences, expect 0 as per function definition
}

// Test case 3: Only one number, occurring odd times
TEST(FindOddTest, SingleElement) {
    std::vector<int> numbers {3};
    EXPECT_EQ(findOdd(numbers), 3);
}

// Test case 4: Multiple odd numbers, only return one with odd occurrence
TEST(FindOddTest, MultipleOddNumbers) {
    std::vector<int> numbers = {5, 7, 7, 5, 5};
    EXPECT_EQ(findOdd(numbers), 5);
}

// Test case 5: Negative numbers
TEST(FindOddTest, NegativeNumbers) {
    std::vector<int> numbers = {-1, -1, -2, -2, -2};
    EXPECT_EQ(findOdd(numbers), -2);
}

// Test case 6: Mixed negative and positive numbers
TEST(FindOddTest, MixedNegativePositiveNumbers) {
    std::vector<int> numbers = {-3, -3, 4, 2, 4, 2, -3, 2, 2};
    EXPECT_EQ(findOdd(numbers), -3);
}

// Test case 7: Large input
TEST(FindOddTest, LargeInput) {
    std::vector<int> numbers(100001, 1);
    numbers.push_back(2);
    EXPECT_EQ(findOdd(numbers), 2);
}

// Test case 8: Repeated elements with odd occurrences
TEST(FindOddTest, RepeatedOddOccurrence) {
    std::vector<int> numbers = {3, 3, 3, 4, 4, 4, 4};
    EXPECT_EQ(findOdd(numbers), 3);
}

// Test case 9: Multiple numbers with even occurrences
TEST(FindOddTest, AllEvenOccurrences) {
    std::vector<int> numbers = {10, 10, 20, 20, 30, 30};
    EXPECT_EQ(findOdd(numbers), 0);
}

// Test case 10: Empty vector
TEST(FindOddTest, EmptyVector) {
    std::vector<int> numbers;
    EXPECT_EQ(findOdd(numbers), 0);
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}