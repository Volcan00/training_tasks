#include <gtest/gtest.h>
#include "../src/HighestScoringWord.h"

// Basic Test Cases
TEST(HighestScoringWordTests, BasicTests) {
    // Single word
    EXPECT_EQ(highestScoringWord("hello"), "hello");

    // Multiple words, one with the highest score
    EXPECT_EQ(highestScoringWord("hello world"), "world");

    // All words having the same score
    EXPECT_EQ(highestScoringWord("abc abc abc"), "abc");

    // Test with a simple sentence
    EXPECT_EQ(highestScoringWord("the quick brown fox"), "brown");
}

// Test Case with Different Character Scores
TEST(HighestScoringWordTests, CharacterScoreTests) {
    // Test a word with high-scoring characters
    EXPECT_EQ(highestScoringWord("a z z"), "z");

    // Another test with varying scores
    EXPECT_EQ(highestScoringWord("a bb ccc dddd"), "dddd");

    // Test with upper and lowercase characters
    EXPECT_EQ(highestScoringWord("Zebra zebra ZEBRA"), "zebra");  // Upper case should not affect result
}

// Edge Case Tests
TEST(HighestScoringWordTests, EdgeCaseTests) {
    // Empty string
    EXPECT_EQ(highestScoringWord(""), "");

    // Single character words
    EXPECT_EQ(highestScoringWord("a b c"), "c");

    // Long word vs shorter words
    EXPECT_EQ(highestScoringWord("abcdef ghij"), "ghij");

    // All same words
    EXPECT_EQ(highestScoringWord("apple apple apple"), "apple");

    // Input with punctuation (punctuation isn't handled in the current implementation)
    EXPECT_EQ(highestScoringWord("hello! world?"), "world?");
}

// Random Test Cases
TEST(HighestScoringWordTests, RandomTests) {
    // Random sentence
    EXPECT_EQ(highestScoringWord("this is a test sentence"), "sentence");

    // Another random test
    EXPECT_EQ(highestScoringWord("go ahead make my day"), "my");

    // Test a long sentence
    EXPECT_EQ(highestScoringWord("supercalifragilisticexpialidocious is hard to spell"), "supercalifragilisticexpialidocious");

    // Repeated high score word
    EXPECT_EQ(highestScoringWord("high high high low"), "low");

    // Single large word with all alphabet letters
    EXPECT_EQ(highestScoringWord("abcdefghijklmnopqrstuvwxyz"), "abcdefghijklmnopqrstuvwxyz");
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}