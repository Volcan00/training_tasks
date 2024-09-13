#include "../src/GetPins.h"
#include <gtest/gtest.h>

// Basic test cases for get_pins function
TEST(GetPinsTest, BasicTests) {
    // Test case 1
    std::vector<std::string> expected1  {"0", "5", "7", "8", "9"};
    EXPECT_EQ(get_pins("8"), expected1);

    // Test case 2
    std::vector<std::string> expected2  {"11", "12", "14", "21", "22", "24", "41", "42", "44"};
    EXPECT_EQ(get_pins("11"), expected2);

    // Test case 3
    std::vector<std::string> expected3  {"236", "238", "239", "256", "258", "259", "266", "268", "269", "296", "298", "299", "336", "338", "339", "356", "358", "359", "366", "368", "369", "396", "398", "399", "636", "638", "639", "656", "658", "659", "666", "668", "669", "696", "698", "699"};
    EXPECT_EQ(get_pins("369"), expected3);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}