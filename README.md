![Version](https://img.shields.io/badge/version-0.6.0-green.svg)
[![License](https://img.shields.io/badge/license-MIT_License-green.svg?style=flat)](LICENSE)
[![Build Status](https://travis-ci.org/karel-burda/test-utils.svg?branch=develop)](https://travis-ci.org/karel-burda/cmake-helpers)
[![Coverage Status](https://coveralls.io/repos/github/karel-burda/test-utils/badge.svg?branch=develop)](https://coveralls.io/github/karel-burda/test-utils?branch=develop)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/cca3592124294efa96b07fa9e32d973d)](https://www.codacy.com/app/karel-burda/test-utils?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=karel-burda/test-utils&amp;utm_campaign=Badge_Grade)

# Important
This project contains git sub-modules that are needed for building example and tests.

If you just want to use the implementation, you can clone **without** sub-modules. In case you want to build example, tests, or use CMake, please, be sure to clone the repository
with `--recurse-submodules` or `--recursive` on older versions of git. Alternatively, you can clone without sub-modules and initialize these later.

# Introduction
`test-utils` features small test-related functions and macros (based on the gtest) I'm using across my project.

Implementation is header-only.

See [include/test-utils](include/test-utils) for main functionality and [tests/unit](tests/unit) for unit tests.

# Usage
In order to use the `test-utils`, it's the `include` directory that matters. Just make sure that the header search path is pointing to the [include](include) directory located in the root directory.

`test-utils` uses macros from the `gtest`, so include path to the `gtest` should also be visible in the final project.

You can use the provided CMake package configuration at [test-utils-config.cmake.in](test-utils-config.cmake.in).

## Examples
For full examples, see implementation of [tests](tests/unit).

### make_all_members_public.hpp
```cpp
// After following include, every member from class or struct that goes after this will have public visibility
#include <test_utils/make_all_members_public.hpp>

#include "some_class.hpp"

// Now we have access to protected and private members of some_class
```

### static_class_assertions.hpp
```cpp
#include <test_utils/static_class_assertions.hpp>

struct some_struct
{
    some_struct() = default;
    ~some_struct() = default;

    some_struct(const some_struct &) = default;
    some_struct & operator=(const some_struct &) = default;

    some_struct & operator=(some_struct &&) = delete;
    some_struct(some_struct &&) = delete;
};

// Following compile time assertions use "static_assert", "is_default_constructible<T>", etc.
// "some_struct" should have default constructor
test_utils::assert_default_constructibility<some_struct, true>();
// "some_struct" should be copy constructible
test_utils::assert_copy_constructibility<some_struct, true>();
// "some_struct" should not be move constructible
test_utils::assert_move_constructibility<some_struct, false>();
```

### test_utils.hpp
```cpp
#include <test_utils/test_utils.hpp>

struct Foo
{
    Foo()
    {
    }

    Foo(std::string, float)
    {
    }
};

// This uses "ASSERT_NO_THROW" macro from the gtest, creates an instance of the object and destructor
// is called as well (when function going out-of-scope)
test_utils::assert_construction_and_destruction<Foo>();
test_utils::assert_construction_and_destruction<Foo>("bar", 1.0f);
```

### time_utils.hpp
```cpp
#include <test_utils/time_utils.hpp>

// Calls test macros "ASSERT_GE" and "ASSERT_LE" in its implementation
test_utils::assert_that_elapsed_time_in_tolerance(7s, 5s, 9s);

// This should yield around 4 seconds, "duration" is of type "std::chrono<double>"
 const auto duration = test_utils::measure_time([]() { std::this_thread::sleep_for(4s); });
```

# Build Process
For generation of project containing the implementation and tests, run the cmake in the top-level directory like this:

`cmake .`

I personally prefer to specify a separate build directory explicitly:

`cmake -Bbuild -H.`

You can of course specify ordinary cmake options like build type (debug, release with debug info, ...), used generator, etc.

# Tests
For unit tests, execute

`cmake . -DUNIT_TESTS:BOOL=ON`

Tests are being run in the Continuous Integration environment and code coverage is inspected.
