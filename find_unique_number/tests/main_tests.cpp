#include <gtest/gtest.h>
#include "../src/FindUniqueNumber.h"

TEST(FindUniqTest, BasicTest1) 
{
    std::vector<float> vec {1, 1, 1, 2, 1, 1};
    EXPECT_FLOAT_EQ(find_uniq(vec), 2.0f);
}

TEST(FindUniqTest, BasicTest2) {
    std::vector<float> vec {0, 0, 0.55f, 0, 0};
    EXPECT_FLOAT_EQ(find_uniq(vec), 0.55f);
}

TEST(FindUniqTest, UniqueAtEnd) {
    std::vector<float> vec {3, 3, 3, 3, 4};
    EXPECT_FLOAT_EQ(find_uniq(vec), 4.0f);
}

TEST(FindUniqTest, UniqueAtBeginning) {
    std::vector<float> vec {7, 6, 6, 6, 6, 6};
    EXPECT_FLOAT_EQ(find_uniq(vec), 7.0f);
}

TEST(FindUniqTest, UniqueInMiddle) {
    std::vector<float> vec {8, 8, 5, 8, 8};
    EXPECT_FLOAT_EQ(find_uniq(vec), 5.0f);
}

TEST(FindUniqTest, LargeArray) {
    std::vector<float> vec(1000000, 1.0f);
    vec[54321] = 2.0f;
    EXPECT_FLOAT_EQ(find_uniq(vec), 2.0f);
}

TEST(FindUniqTest, RandomValues) {
    std::vector<float> vec {9.999f, 9.999f, 9.999f, 1.001f, 9.999f};
    EXPECT_FLOAT_EQ(find_uniq(vec), 1.001f);
}

TEST(FindUniqTest, NegativeNumbers) {
    std::vector<float> vec {-10.5f, -10.5f, -10.5f, -10.5f, -3.14f};
    EXPECT_FLOAT_EQ(find_uniq(vec), -3.14f);
}

TEST(FindUniqTest, SmallEpsilon) {
    std::vector<float> vec {1.00001f, 1.00001f, 1.0f, 1.00001f, 1.00001f};
    EXPECT_FLOAT_EQ(find_uniq(vec), 1.0f);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}