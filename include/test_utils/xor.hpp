#pragma once

#include <iso646.h>

#include <gtest/gtest.h>

#define _BURDA_TEST_UTILS_XOR_EXPRESSION condition1 xor condition2

#define BURDA_TEST_UTILS_XOR_EXPECT(condition1, condition2) EXPECT_TRUE(_BURDA_TEST_UTILS_XOR_EXPRESSION);
#define BURDA_TEST_UTILS_XOR_ASSERT(condition1, condition2) ASSERT_TRUE(_BURDA_TEST_UTILS_XOR_EXPRESSION);
