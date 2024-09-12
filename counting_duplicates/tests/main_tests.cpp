#include "../src/CountingDuplicates.h"
#include <gtest/gtest.h>

// Basic test case: No duplicates
TEST(DuplicateCountTest, NoDuplicates) {
    std::string input = "abcdef";
    int expected = 0;
    
    EXPECT_EQ(duplicateCount(input), expected);
}

// Basic test case: All duplicates
TEST(DuplicateCountTest, AllDuplicates) {
    std::string input = "aabbcc";
    int expected = 3;
    
    EXPECT_EQ(duplicateCount(input), expected);
}

// Test case: Case-insensitive duplicates
TEST(DuplicateCountTest, CaseInsensitiveDuplicates) {
    std::string input = "AaBbCc";
    int expected = 3; 
    
    EXPECT_EQ(duplicateCount(input), expected);
}

// Test case: Mix of duplicates and unique
TEST(DuplicateCountTest, MixedCase) {
    std::string input = "AaBbCcDdEeF";
    int expected = 5;
    
    EXPECT_EQ(duplicateCount(input), expected);
}

// Random test case: Complex string
TEST(DuplicateCountTest, RandomString) {
    std::string input = "aA1bB2ccddEE";
    int expected = 5;
    
    EXPECT_EQ(duplicateCount(input), expected);
}

// Random test case: Special characters
TEST(DuplicateCountTest, SpecialCharacters) {
    std::string input = "!!@@##$$%%^^";
    int expected = 6;
    
    EXPECT_EQ(duplicateCount(input), expected);
}

// Test case: Empty string
TEST(DuplicateCountTest, EmptyString) {
    std::string input = "";
    int expected = 0;
    
    EXPECT_EQ(duplicateCount(input), expected);
}

// Test case: Single character string
TEST(DuplicateCountTest, SingleCharacterString) {
    std::string input = "a";
    int expected = 0;

    EXPECT_EQ(duplicateCount(input), expected);
}

// Test case: String with numbers
TEST(DuplicateCountTest, NumbersInString) {
    std::string input = "112233";
    int expected = 3;
    
    EXPECT_EQ(duplicateCount(input), expected);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}