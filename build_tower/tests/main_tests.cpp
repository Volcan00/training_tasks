#include "../src/BuildTower.h"
#include <gtest/gtest.h>

// Basic test for one floor
TEST(TowerBuilderTest, OneFloor) {
    unsigned nFloors = 1;
    std::vector<std::string> expected = {"*"};
    std::vector<std::string> result = towerBuilder(nFloors);
    
    ASSERT_EQ(result, expected);
}

// Basic test for two floors
TEST(TowerBuilderTest, TwoFloors) {
    unsigned nFloors = 2;
    std::vector<std::string> expected = {
        " * ", 
        "***"
    };
    std::vector<std::string> result = towerBuilder(nFloors);
    
    ASSERT_EQ(result, expected);
}

// Edge case for zero floors
TEST(TowerBuilderTest, ZeroFloors) {
    unsigned nFloors = 0;
    std::vector<std::string> expected = {};
    std::vector<std::string> result = towerBuilder(nFloors);
    
    ASSERT_EQ(result, expected);
}

// Random test for three floors
TEST(TowerBuilderTest, ThreeFloors) {
    unsigned nFloors = 3;
    std::vector<std::string> expected = {
        "  *  ", 
        " *** ", 
        "*****"
    };
    std::vector<std::string> result = towerBuilder(nFloors);
    
    ASSERT_EQ(result, expected);
}

// Random test for five floors
TEST(TowerBuilderTest, FiveFloors) {
    unsigned nFloors = 5;
    std::vector<std::string> expected = {
        "    *    ",
        "   ***   ",
        "  *****  ",
        " ******* ",
        "*********"
    };
    std::vector<std::string> result = towerBuilder(nFloors);
    
    ASSERT_EQ(result, expected);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}