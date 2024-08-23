#include "../src/Convert.h"
#include "gtest/gtest.h"

// Basic test case: Conversion of 0 to IP address
TEST(Uint32ToIpTest, BasicTest1) {
    std::string expected { "0.0.0.0" };
    std::string result { uint32_to_ip(0) };
    EXPECT_EQ(result, expected);
}

// Basic test case: Conversion of 1 to IP address
TEST(Uint32ToIpTest, BasicTest2) {
    std::string expected { "0.0.0.1" };
    std::string result { uint32_to_ip(1) };
    EXPECT_EQ(result, expected);
}

// Basic test case: Conversion of maximum 32-bit unsigned integer
TEST(Uint32ToIpTest, BasicTest3) {
    std::string expected { "255.255.255.255" };
    std::string result { uint32_to_ip(4294967295) };  // 0xFFFFFFFF
    EXPECT_EQ(result, expected);
}

// Basic test case: Conversion of 3232235777 to IP address (192.168.1.1)
TEST(Uint32ToIpTest, BasicTest4) {
    std::string expected { "192.168.1.1" };
    std::string result { uint32_to_ip(3232235777) };  // 0xC0A80101
    EXPECT_EQ(result, expected);
}

// Random test case: Conversion of 167772161 to IP address (10.0.0.1)
TEST(Uint32ToIpTest, RandomTest1) {
    std::string expected { "10.0.0.1" };
    std::string result { uint32_to_ip(167772161) };  // 0x0A000001
    EXPECT_EQ(result, expected);
}

// Random test case: Conversion of 2886729728 to IP address (172.16.0.0)
TEST(Uint32ToIpTest, RandomTest2) {
    std::string expected { "172.16.0.0" };
    std::string result { uint32_to_ip(2886729728) };  // 0xAC100000
    EXPECT_EQ(result, expected);
}

// Random test case: Conversion of 2130706433 to IP address (127.0.0.1)
TEST(Uint32ToIpTest, RandomTest3) {
    std::string expected { "127.0.0.1" };
    std::string result { uint32_to_ip(2130706433) };  // 0x7F000001
    EXPECT_EQ(result, expected);
}

// Random test case: Conversion of 4294967040 to IP address (255.255.255.0)
TEST(Uint32ToIpTest, RandomTest4) {
    std::string expected { "255.255.255.0" };
    std::string result { uint32_to_ip(4294967040) };  // 0xFFFFFF00
    EXPECT_EQ(result, expected);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}