#pragma once

#include <gtest/gtest.h>

#define _BURDA_TEST_UTILS_ARRAY_FOREACH(array1, array2, size, assert_type) \
ASSERT_NE(array1, nullptr); \
ASSERT_NE(array2, nullptr); \
ASSERT_GE(size, 0) << "Size has to be greater than 0"; \
\
for (size_t i = 0; i < size; ++i) \
{ \
    assert_type(array1[i], array2[i]) << "Check failed at index " << std::to_string(i); \
}

#define BURDA_TEST_UTILS_ARRAY_EXPECT_EQUAL(array1, array2, size) _BURDA_TEST_UTILS_ARRAY_FOREACH(array1, array2, size, EXPECT_EQ)
#define BURDA_TEST_UTILS_ARRAY_ASSERT_EQUAL(array1, array2, size) _BURDA_TEST_UTILS_ARRAY_FOREACH(array1, array2, size, ASSERT_EQ)
