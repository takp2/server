#include "crc16.cpp"

#include <gtest/gtest.h>

#include "crc32.cpp"

TEST(crc32, TestCRC16) {
	const unsigned char *buffer = (const unsigned char *)"123456789";
	auto result = CRC16(buffer, 9, 1);
	EXPECT_EQ(result, 45711);
}