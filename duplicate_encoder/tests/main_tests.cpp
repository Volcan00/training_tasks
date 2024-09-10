#include <gtest/gtest.h>
#include "../src/DuplicateEncoder.h"

// Basic Test Cases
TEST(DuplicateEncoderTests, BasicTests) {
    // Test with no repeating characters
    EXPECT_EQ(duplicate_encoder("abcde"), "(((((");
    
    // Test with all repeating characters
    EXPECT_EQ(duplicate_encoder("aabbcc"), "))))))");

    // Test with mixed repeating and non-repeating characters
    EXPECT_EQ(duplicate_encoder("aAAbCCc"), ")))()))");

    // Test with a single character
    EXPECT_EQ(duplicate_encoder("x"), "(");

    // Test with an empty string
    EXPECT_EQ(duplicate_encoder(""), "");
}

// Case Insensitivity Tests
TEST(DuplicateEncoderTests, CaseInsensitiveTests) {
    // Test case insensitivity
    EXPECT_EQ(duplicate_encoder("AaBbCc"), "))))))");
    EXPECT_EQ(duplicate_encoder("AaAa"), "))))");
    EXPECT_EQ(duplicate_encoder("Abab"), "))))");
}

// Random/Edge Case Tests
TEST(DuplicateEncoderTests, RandomEdgeCaseTests) {
    // Test with spaces (which are treated like any other character)
    EXPECT_EQ(duplicate_encoder("hello world"), "(()))(()()(");
    
    // Test with special characters
    EXPECT_EQ(duplicate_encoder("!@#$%^"), "((((((");

    // Test with numbers
    EXPECT_EQ(duplicate_encoder("112233"), "))))))");

    // Test with a mix of numbers, special characters, and letters
    EXPECT_EQ(duplicate_encoder("a1A!2@bB"), ")()((())");
    
    // Test long string with many repeating and non-repeating characters
    std::string long_string = "AaBbCc1234567890!@#$%^&*()_+";
    EXPECT_EQ(duplicate_encoder(long_string), "))))))((((((((((((((((((((((");
}

// Performance Test
TEST(DuplicateEncoderTests, PerformanceTest) {
    std::string longString(1000000, 'a'); // String with 1 million 'a's
    EXPECT_EQ(duplicate_encoder(longString), std::string(1000000, ')'));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}