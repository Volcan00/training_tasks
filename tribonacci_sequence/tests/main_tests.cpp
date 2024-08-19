#include <gtest/gtest.h>
#include <random>
#include <algorithm>
#include "../src/Tribonacci.h"

// Test case 1: Tribonacci with n = 0
TEST(TribonacciTest, ZeroLength) 
{
    std::vector<int> signature {1, 1, 1};
    int n { 0 };
    std::vector<int> result { tribonacci(signature, n) };

    EXPECT_EQ(result.size(), 0);
}

// Test case 2: Tribonacci with n = 1
TEST(TribonacciTest, LengthOne) 
{
    std::vector<int> signature {1, 1, 1};
    int n { 1 };
    std::vector<int> result { tribonacci(signature, n) };

    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result, (std::vector<int>{1}));
}

// Test case 3: Tribonacci with n = 3 (returns just the signature)
TEST(TribonacciTest, LengthThree) 
{
    std::vector<int> signature {1, 1, 1};
    int n { 3 };
    std::vector<int> result { tribonacci(signature, n) };

    EXPECT_EQ(result.size(), 3);
    EXPECT_EQ(result, (std::vector<int>{1, 1, 1}));
}
// Test case 4: Tribonacci with n = 10 and a basic signature
TEST(TribonacciTest, BasicSequence) {
    std::vector<int> signature {0, 1, 1};
    int n { 10 };
    std::vector<int> result { tribonacci(signature, n) };

    std::vector<int> expected {0, 1, 1, 2, 4, 7, 13, 24, 44, 81};
    EXPECT_EQ(result, expected);
}

// Test case 5: Tribonacci with n = 5 and another signature
TEST(TribonacciTest, CustomSignature) 
{
    std::vector<int> signature {2, 3, 5};
    int n { 5 };
    std::vector<int> result { tribonacci(signature, n) };

    std::vector<int> expected {2, 3, 5, 10, 18};
    EXPECT_EQ(result, expected);
}

// Utility function to manually compute the tribonacci sequence
std::vector<int> computeTribonacci(const std::vector<int>& signature, int n) {
    std::vector<int> result { signature };
    result.resize(n);
    for (int i = 3; i < n; ++i) {
        result[i] = result[i - 1] + result[i - 2] + result[i - 3];
    }
    return result;
}

// Test case 1: Random signature with n = 10
TEST(TribonacciTest, RandomSignature) 
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 100);

    std::vector<int> signature {distrib(gen), distrib(gen), distrib(gen)};
    int n { 10 };
    
    std::vector<int> result { tribonacci(signature, n) };
    std::vector<int> expected { computeTribonacci(signature, n) };

    EXPECT_EQ(result, expected);
}

// Test case 2: Random signature with larger n (n = 20)
TEST(TribonacciTest, RandomSignatureLargeN) 
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 100);

    std::vector<int> signature {distrib(gen), distrib(gen), distrib(gen)};
    int n { 20 };
    
    std::vector<int> result { tribonacci(signature, n) };
    std::vector<int> expected { computeTribonacci(signature, n) };

    EXPECT_EQ(result, expected);
}

// Test case 3: Random signature with n = 3 (should return the signature itself)
TEST(TribonacciTest, RandomSignatureSmallN) 
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 100);

    std::vector<int> signature {distrib(gen), distrib(gen), distrib(gen)};
    int n { 3 };

    std::vector<int> result { tribonacci(signature, n) };

    // For n = 3, the output should be just the signature
    EXPECT_EQ(result, signature);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}