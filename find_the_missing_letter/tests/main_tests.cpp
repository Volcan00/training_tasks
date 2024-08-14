#include "../src/FindMissingLetter.h"
#include <gtest/gtest.h>
#include <random>
#include <algorithm>

TEST(FindMissingLetterTest, BasicTests)
{
    EXPECT_EQ(findMissingLetter({ 'x', 'z'}), 'y');
    EXPECT_EQ(findMissingLetter({ 'm', 'o', 'p'}), 'n');
    EXPECT_EQ(findMissingLetter({ 'a', 'b', 'c', 'd', 'f' }), 'e');
    EXPECT_EQ(findMissingLetter({ 'O', 'Q', 'R', 'S' }), 'P');
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}