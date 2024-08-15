#include <gtest/gtest.h>
#include <random>
#include "../src/FCFS.h"

TEST(FCFSTest, EmptyProcessVector) {
    std::vector<std::pair<int, int>> processes;
    std::vector<double> result = fcfs(processes);
    EXPECT_EQ(result.size(), 4); // Check for correct number of results
    for (double value : result) {
        EXPECT_EQ(value, 0.0); // Expect all values to be 0 for empty vector
    }
}

TEST(FCFSTest, SingleProcess) {
    std::vector<std::pair<int, int>> processes = {{0, 5}};
    std::vector<double> result = fcfs(processes);
    EXPECT_EQ(result.size(), 4);
    EXPECT_EQ(result[0], 5.00);
    EXPECT_EQ(result[1], 5.00);
    EXPECT_EQ(result[2], 0.00);
    EXPECT_EQ(result[3], 5.00);
}

TEST(FCFSTest, MultipleProcesses) {
    std::vector<std::pair<int, int>> processes = {{0, 5}, {2, 3}, {4, 1}};
    std::vector<double> result = fcfs(processes);
    EXPECT_EQ(result.size(), 4);
    EXPECT_NEAR(result[0], 7.33, 0.01);
    EXPECT_NEAR(result[1], 5.33, 0.01);
    EXPECT_NEAR(result[2], 2.33, 0.01);
    EXPECT_EQ(result[3], 3.00);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}