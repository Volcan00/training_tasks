#include "../src/MexicanWave.h"
#include <gtest/gtest.h>

// Basic test case: Single word
TEST(WaveTest, BasicWord) {
    std::string input = "hello";
    std::vector<std::string> expected = {
        "Hello", 
        "hEllo", 
        "heLlo", 
        "helLo", 
        "hellO"
    };

    EXPECT_EQ(wave(input), expected);
}

// Test case: Empty string
TEST(WaveTest, EmptyString) {
    std::string input = "";
    std::vector<std::string> expected = {}; // No wave in an empty string

    EXPECT_EQ(wave(input), expected);
}

// Test case: String with spaces
TEST(WaveTest, StringWithSpaces) {
    std::string input = "hello world";
    std::vector<std::string> expected = {
        "Hello world", 
        "hEllo world", 
        "heLlo world", 
        "helLo world", 
        "hellO world", 
        "hello World", 
        "hello wOrld", 
        "hello woRld", 
        "hello worLd", 
        "hello worlD"
    };

    EXPECT_EQ(wave(input), expected);
}

// Test case: String with special characters
TEST(WaveTest, StringWithSpecialCharacters) {
    std::string input = "he!!o";
    std::vector<std::string> expected = {
        "He!!o", 
        "hE!!o", 
        "he!!O"
    };

    EXPECT_EQ(wave(input), expected);
}

// Test case: Random string
TEST(WaveTest, RandomString) {
    std::string input = "abc def";
    std::vector<std::string> expected = {
        "Abc def", 
        "aBc def", 
        "abC def", 
        "abc Def", 
        "abc dEf", 
        "abc deF"
    };

    EXPECT_EQ(wave(input), expected);
}

// Test case: Single character
TEST(WaveTest, SingleCharacter) {
    std::string input = "a";
    std::vector<std::string> expected = {"A"};

    EXPECT_EQ(wave(input), expected);
}

// Test case: Single character with space
TEST(WaveTest, SingleCharacterWithSpace) {
    std::string input = " a ";
    std::vector<std::string> expected = {" A "};

    EXPECT_EQ(wave(input), expected);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}