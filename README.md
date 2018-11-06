![Version](https://img.shields.io/badge/version-1.0.0-green.svg)
[![License](https://img.shields.io/badge/license-MIT_License-green.svg?style=flat)](LICENSE)
[![Build Status](https://travis-ci.org/karel-burda/test-utils.svg?branch=develop)](https://travis-ci.org/karel-burda/test-utils)
[![Coverage Status](https://coveralls.io/repos/github/karel-burda/test-utils/badge.svg?branch=develop)](https://coveralls.io/github/karel-burda/test-utils?branch=develop)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/cca3592124294efa96b07fa9e32d973d)](https://www.codacy.com/app/karel-burda/test-utils?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=karel-burda/test-utils&amp;utm_campaign=Badge_Grade)

# Important
This project contains git sub-modules that are needed for building example and tests.

If you just want to use the implementation, you can clone **without** sub-modules. In case you want to build example, tests, or use CMake, please, be sure to clone the repository
with `--recurse-submodules` or `--recursive` on older versions of git. Alternatively, you can clone without sub-modules and initialize these later.

# Introduction
`test-utils` features small test-related functions and macros (based on the gtest) I'm using across my project.

Implementation is header-only.

See [include/test_utils](include/test_utils) for main functionality and [tests/unit](tests/unit) for unit tests.

# Usage
There are basically these options when it comes to build system integration:

## 1. CMake Way
Recommended option.

There are essentially these ways options of how to use this package that depends on your preferences our build architecture:

### A) Generate directly

Call `add_subdirectory(...)` directly in your CMakeLists;

```cmake
add_executable("my-project" main.cpp)

# Example add_subdirectory(test-utils ${CMAKE_BINARY_DIR}/test-utils EXCLUDE_FROM_ALL)
add_subdirectory(<path-to-test-utils>)

if (TARGET test-utils)
    add_library(burda::test-utils ALIAS test-utils)

    # This will import header search paths, compile definitions and other dependencies of the test-utils as well
    target_link_libraries("my-project" test-utils)
endif()
```

### B) Generate separately

Generation phase on the test-utils is run separately, that means that you run:
```cmake
# Example: cmake -Bbuild/test-utils -Htest-utils in the root of your project 
cmake <path-to-test-utils>
```

This will create automatically generated package configuration file `test-utils-config.cmake` that contains exported target and all important information.

Then you can do this in your CMakeLists:

```cmake
add_executable("my-project" main.cpp)

find_package(test-utils CONFIG PATHS <path-to-binary-dir-of-test-utils>)
# Alternatively assuming that the "test-utils_DIR" variable is set: find_package(test-utils CONFIG)

# This will import header search paths, compile definitions and other dependencies of the test-utils as well
target_link_libraries("my-project" burda::test-utils)
```

## 2. Manual Way
It's mainly the `include` directory that matters so make sure, the compiler will see it.

You might have to manually set certain compiler (not only) settings though.

## Examples
For full examples, see implementation of [tests](tests/unit).

### [make_all_members_public.hpp](include/test-utils/make_all_members_public.cpp)
Test implemented at: [make_all_members_public_test.cpp](tests/unit/src/make_all_members_public_test.cpp)
```cpp
// after following include, every member from class or struct that goes after this will have public visibility
#include <test_utils/make_all_members_public.hpp>

#include "some_class.hpp"

// now we have access to protected and private members of some_class
```

### [static_class_assertions.hpp](include/test-utils/static_class_assertions.cpp)
Test implemented at: [static_class_assertions_test.cpp](tests/unit/src/static_class_assertions_test.cpp)
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

// following compile time assertions use "static_assert", "is_default_constructible<T>", etc.
// "some_struct" should have default constructor
burda::test_utils::assert_default_constructibility<some_struct, true>();
// "some_struct" should be copy constructible
burda::test_utils::assert_copy_constructibility<some_struct, true>();
// "some_struct" should not be move constructible
burda::test_utils::assert_move_constructibility<some_struct, false>();
```

### [test_utils.hpp](include/test-utils/test_utils.cpp)
Test implemented at: [test_utils_test.cpp](tests/unit/src/test_utils_test.cpp)
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

// this uses "ASSERT_NO_THROW" macro from the gtest, creates an instance of the object and destructor
// is called as well (when function going out-of-scope)
burda::test_utils::assert_construction_and_destruction<Foo>();
burda::test_utils::assert_construction_and_destruction<Foo>("bar", 1.0f);
```

### [time_utils.hpp](include/test-utils/time_utils.cpp)
Test implemented at: [time_utils_test.cpp](tests/unit/src/time_utils_test.cpp)
```cpp
#include <test_utils/time_utils.hpp>

// calls test macros "ASSERT_GE" and "ASSERT_LE" in its implementation
burda::test_utils::assert_that_elapsed_time_in_tolerance(7s, 5s, 9s);
```

# Unit Tests
For building tests, run cmake in the source directory [tests/unit](tests/unit):

```cmake
cmake -Bbuild -H.
# You can also add coverage by appending "-DCOVERAGE:BOOL=ON"
cmake -Bbuild/tests/unit -Htests/unit -DCMAKE_BUILD_TYPE:STRING=RelWithDebInfo
cmake --build build/tests/unit --config RelWithDebInfo
# Or you can build target "run-all-tests-verbose" that will also run the tests with certain timeout:
# cmake --build build/tests/unit --target run-all-tests-verbose --config RelWithDebInfo
```

For more info, see [.travis.yml](.travis.yml).

# Continuous Integration
Continuous Integration is now being run Linux (with GCC 5.x) on Travis: https://travis-ci.org/karel-burda/test-utils.

Compilers are set-up to treat warnings as errors and with pedantic warning level. Targets are built in a release mode with debug symbols and code coverage measure).

The project is using just one stage (because of the overhead of spawning other stages)
* `tests (C++14)` -- cppcheck, build (linux, gcc5), tests

Project uses [coveralls.io](https://coveralls.io/github/karel-burda/test-utils) for code coverage summary and [codacy](https://app.codacy.com/app/karel-burda/test-utils/dashboard) for the coding style and additional static analysis.
