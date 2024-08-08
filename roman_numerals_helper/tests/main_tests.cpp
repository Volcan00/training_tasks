#include <gtest/gtest.h>
#include <ctime>
#include "../src/RomanHelper.h"

TEST(RomanHelperTest, ToRomanBasicTest)
{
    RomanHelper rh {};
    EXPECT_EQ(rh.to_roman(1), "I");
    EXPECT_EQ(rh.to_roman(4), "IV");
    EXPECT_EQ(rh.to_roman(9), "IX");
    EXPECT_EQ(rh.to_roman(40), "XL");
    EXPECT_EQ(rh.to_roman(90), "XC");
    EXPECT_EQ(rh.to_roman(400), "CD");
    EXPECT_EQ(rh.to_roman(900), "CM");
    EXPECT_EQ(rh.to_roman(3999), "MMMCMXCIX");
}

TEST(RomanHelperTest, FromRomanBasicTest)
{
    RomanHelper rh;
    EXPECT_EQ(rh.from_roman("I"), 1);
    EXPECT_EQ(rh.from_roman("IV"), 4);
    EXPECT_EQ(rh.from_roman("IX"), 9);
    EXPECT_EQ(rh.from_roman("XL"), 40);
    EXPECT_EQ(rh.from_roman("XC"), 90);
    EXPECT_EQ(rh.from_roman("CD"), 400);
    EXPECT_EQ(rh.from_roman("CM"), 900);
    EXPECT_EQ(rh.from_roman("MMMCMXCIX"), 3999);
}

TEST(RomanHelperTest, ToRomanEdgeCases)
{
    RomanHelper rh;
    EXPECT_EQ(rh.to_roman(0), "Entered number is out of range!\n");
    EXPECT_EQ(rh.to_roman(4000), "Entered number is out of range!\n");
    EXPECT_EQ(rh.to_roman(-5), "Entered number is out of range!\n");
}

TEST(RomanHelperTest, RoundTripConversion) 
{
    RomanHelper rh;
    for (int i = 1; i <= 3999; ++i) {
        std::string roman = rh.to_roman(i);
        unsigned int result = rh.from_roman(roman);
        EXPECT_EQ(result, i) << "Failed on number: " << i;
    }
}

TEST(RomanHelperTest, RandomTest)
{
    RomanHelper rh {};
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for(int i = 0; i < 10; ++i)
    {
        int randomNum { rand() % 3999 + 1 };
        std::string roman { rh.to_roman(randomNum) };
        unsigned int convertedBack { rh.from_roman(roman) };
        EXPECT_EQ(convertedBack, randomNum) << "Failed on random number: " << randomNum;
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}