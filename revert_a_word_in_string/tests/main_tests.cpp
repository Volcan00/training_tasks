#include "../src/WordRevert.h"
#include <gtest/gtest.h>

TEST(SpinWordsTest, BasicTests) {
    // Test with no word greater than 5 characters
    EXPECT_EQ(spinWords("This is a test"), "This is a test");
    
    // Test with a single word greater than 5 characters
    EXPECT_EQ(spinWords("Welcome"), "emocleW");
    
    // Test with a sentence where only one word has more than 5 characters
    EXPECT_EQ(spinWords("Hey fellow warriors"), "Hey wollef sroirraw");

    // Test with all words greater than 5 characters
    EXPECT_EQ(spinWords("This sentence has reversed words"), "This ecnetnes has desrever sdrow");
}

TEST(SpinWordsTest, EmptyStringTest) {
    // Test with an empty string
    EXPECT_EQ(spinWords(""), "");
}

TEST(SpinWordsTest, SingleWordTests) {
    // Test with a single word less than or equal to 5 characters
    EXPECT_EQ(spinWords("short"), "trohs");

    // Test with a single word longer than 5 characters
    EXPECT_EQ(spinWords("longword"), "drowgnol");
}

TEST(SpinWordsTest, MultipleSpacesTest) {
    // Test with multiple spaces between words
    EXPECT_EQ(spinWords("This  has  multiple  spaces"), "This has elpitlum secaps");

    // Test with spaces before and after the words
    EXPECT_EQ(spinWords("   Leading and trailing spaces   "), "gnidaeL and gniliart secaps ");
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}