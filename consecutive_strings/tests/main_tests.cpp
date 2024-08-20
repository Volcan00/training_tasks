#include <gtest/gtest.h>
#include "../src/ConsecutiveStrings.h"

// Test case 1: Standard case with various strings
TEST(LongestConsecTest, BasicTest1) 
{
    std::vector<std::string> strArr { "tree", "foling", "trashy", "blue", "abcdef", "uvwxyz" };
    int k { 2 };
    EXPECT_EQ(LongestConsec::longestConsec(strArr, k), "folingtrashy");
}

// Test case 2: Another standard case
TEST(LongestConsecTest, BasicTest2) 
{
    std::vector<std::string> strArr { "zone", "abigail", "theta", "form", "libe", "zas", "theta", "abigail" };
    int k { 2 };
    EXPECT_EQ(LongestConsec::longestConsec(strArr, k), "abigailtheta");
}

// Test case 3: k = 1, should return the longest individual string
TEST(LongestConsecTest, EdgeCaseK1) 
{
    std::vector<std::string> strArr { "one", "two", "three" };
    int k { 1 };
    EXPECT_EQ(LongestConsec::longestConsec(strArr, k), "three");
}

// Test case 4: Empty array, should return empty string
TEST(LongestConsecTest, EdgeCaseEmptyArray) 
{
    std::vector<std::string> strArr {};
    int k { 2 };
    EXPECT_EQ(LongestConsec::longestConsec(strArr, k), "");
}

// Test case 5: k greater than array size, should return empty string
TEST(LongestConsecTest, EdgeCaseKGreaterThanSize) 
{
    std::vector<std::string> strArr { "a", "b", "c" };
    int k { 4 };
    EXPECT_EQ(LongestConsec::longestConsec(strArr, k), "");
}

// Test case 6: k = 0, should return empty string
TEST(LongestConsecTest, EdgeCaseKZero) 
{
    std::vector<std::string> strArr { "a", "b", "c" };
    int k { 0 };
    EXPECT_EQ(LongestConsec::longestConsec(strArr, k), "");
}

// Test case 7: All strings are the same
TEST(LongestConsecTest, AllStringsSame) 
{
    std::vector<std::string> strArr { "repeat", "repeat", "repeat", "repeat" };
    int k { 3 };
    EXPECT_EQ(LongestConsec::longestConsec(strArr, k), "repeatrepeatrepeat");
}

// Test case 8: Very large strings
TEST(LongestConsecTest, LargeStrings) 
{
    std::vector<std::string> strArr { 
        std::string(1000, 'a'), 
        std::string(2000, 'b'), 
        std::string(3000, 'c') 
    };
    int k { 2 };
    std::string expected = std::string(2000, 'b') + std::string(3000, 'c');
    EXPECT_EQ(LongestConsec::longestConsec(strArr, k), expected);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}