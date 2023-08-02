#include "crc32.h"

#include <gtest/gtest.h>

TEST(common_crc32, TestFinish) {
	uint32 test = CRC32::Finish(1) & 0xffff;
	EXPECT_EQ(test, 65534);
}