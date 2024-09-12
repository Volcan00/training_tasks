#include "../src/Tour.h"
#include <gtest/gtest.h>
#include <cmath>

// Basic test case
TEST(TourTest, BasicTest) {
    // Define example input data
    std::vector<std::string> arrFriends {"A1", "A2", "A3", "A4"};
    std::vector<std::vector<std::string>> ftwns {{"A1", "X1"}, {"A2", "X2"}, {"A3", "X3"}, {"A4", "X4"}};
    stringdblmap h = {{"X1", 100.0}, {"X2", 200.0}, {"X3", 250.0}, {"X4", 300.0}};

    // Expected output
    int expectedDistance { 889 }; // Manually calculated distance

    // Call the tour function and check if the result matches the expected value
    EXPECT_EQ(Tour::tour(arrFriends, ftwns, h), expectedDistance);
}

// Test case for handling missing friends/towns
TEST(TourTest, MissingFriendsAndTownsTest) {
    // Define input where some friends have no corresponding towns
    std::vector<std::string> arrFriends {"A1", "A2", "A3", "A4"};
    std::vector<std::vector<std::string>> ftwns {{"A1", "X1"}, {"A3", "X3"}};
    stringdblmap h = {{"X1", 100.0}, {"X3", 250.0}};

    // Expected output
    int expectedDistance { 579 }; // Skips A2 and A4 since their towns are unknown

    // Call the tour function and check if the result matches the expected value
    EXPECT_EQ(Tour::tour(arrFriends, ftwns, h), expectedDistance);
}

// Randomized test case
TEST(TourTest, RandomTest) {
    // Random input
    std::vector<std::string> arrFriends {"A1", "A2", "A3", "A4", "A5"};
    std::vector<std::vector<std::string>> ftwns {{"A1", "X1"}, {"A3", "X3"}, {"A5", "X5"}};
    stringdblmap h = {{"X1", 150.0}, {"X3", 300.0}, {"X5", 500.0}};

    // Manually calculated expected result
    // Travel: X0 -> X1 -> X3 -> X5 -> X0
    // sqrt(300^2 - 150^2) + sqrt(500^2 - 300^2) + 500
    int expectedDistance { 1309 };

    // Call the tour function and check if the result matches the expected value
    EXPECT_EQ(Tour::tour(arrFriends, ftwns, h), expectedDistance);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}