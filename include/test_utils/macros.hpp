#pragma once

#include <gtest/gtest.h>

#define BURDA_TEST_UTILS_EXPECT_XOR(condition1, condition2) EXPECT_TRUE(condition1 xor condition2);
#define BURDA_TEST_UTILS_ASSERT_XOR(condition1, condition2) EXPECT_TRUE(condition1 xor condition2);
