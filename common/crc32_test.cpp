#include "crc32.h"

#include <gtest/gtest.h>

TEST(CRC32, Finish) {
	uint32 test = CRC32::Finish(1) & 0xffff;
	EXPECT_EQ(test, 65534);
}