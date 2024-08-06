#include <gtest/gtest.h>
#include <ctime>
#include "../src/PigLatin.h"

// Helper function to generate a random string
std::string generateRandomString(size_t length) {
    const std::string CHARACTERS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string PUNCTUATION = ".,!?";
    std::string randomString;

    for (size_t i = 0; i < length; ++i) {
        int randomIndex = rand() % (CHARACTERS.size() + PUNCTUATION.size());
        if (randomIndex < CHARACTERS.size()) {
            randomString += CHARACTERS[randomIndex];
        } else {
            randomString += PUNCTUATION[randomIndex - CHARACTERS.size()];
        }
    }

    return randomString;
}

TEST(PigLatinTest, BasicConversion) {
    EXPECT_EQ(pig_it("Pig latin is cool"), "igPay atinlay siay oolcay");
    EXPECT_EQ(pig_it("Hello world !"), "elloHay orldway !");
}

TEST(PigLatinTest, PunctuationOnly) {
    EXPECT_EQ(pig_it("!"), "!");
    EXPECT_EQ(pig_it(".,!?"), ".,!?");
}

TEST(PigLatinTest, EmptyString) {
    EXPECT_EQ(pig_it(""), "");
}

TEST(PigLatinTest, SingleWord) 
{
    EXPECT_EQ(pig_it("Pig"), "igPay");
    EXPECT_EQ(pig_it("latin"), "atinlay");
}

TEST(PigLatinTest, RandomTest)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for(int i = 0; i < 100; ++i)
    {
        std::string randomString { generateRandomString(50) };
        std::string expected { transformWord(randomString) };
        EXPECT_EQ(pig_it(randomString), expected);
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}