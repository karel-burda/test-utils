![Version](https://img.shields.io/badge/version-1.2.3-blue.svg)
[![License](https://img.shields.io/badge/license-MIT_License-blue.svg?style=flat)](LICENSE)
[![Build Status](https://travis-ci.org/karel-burda/test-utils.svg?branch=master)](https://travis-ci.org/karel-burda/test-utils)
[![Codecov Status](https://codecov.io/gh/karel-burda/test-utils/branch/master/graph/badge.svg)](https://codecov.io/gh/karel-burda/test-utils/branch/master)

## Important
This project contains git sub-modules that are needed for building tests.

If you just want to use the implementation, you can clone without sub-modules. In case you want to build the tests, be sure to clone the repository
with `--recurse-submodules` or `--recursive` on older versions of git. Alternatively, you can clone without sub-modules and initialize these later.

## Introduction
`test-utils` features small test-related functions and macros (based on the gtest) I'm using across my project.

Implementation is header-only and written in C++ 14 and tested on Windows, Linux and OS X.

See [include/test_utils](include/test_utils) for main functionality and [tests/unit](tests/unit) for unit tests.

## Usage
There are basically these options when it comes to build system integration:

### 1. CMake Way
Recommended option.

There are essentially these ways of how to use this package depending on your preferences our build architecture:

#### A) Generate directly

Call `add_subdirectory(...)` directly in your CMakeLists.txt:

```cmake
add_executable(my-project main.cpp)

add_subdirectory(<path-to-test-utils>)
# example: add_subdirectory(test-utils ${CMAKE_BINARY_DIR}/test-utils)

# query package version
message(STATUS "Current version of test-utils is: ${test-utils_VERSION}")

add_library(burda::test-utils ALIAS test-utils)

# this will import search paths, compile definitions and other dependencies of the test-utils as well
target_link_libraries(my-project test-utils)
# or with private visibility: target_link_libraries(my-project PRIVATE test-utils)

```

#### B) Generate separately

Generation phase on the test-utils is run separately, that means that you run:
```cmake
cmake <path-to-test-utils>
# example: cmake -Bbuild/test-utils -Htest-utils in the root of your project 
```

This will create automatically generated package configuration file `test-utils-config.cmake` that contains exported target and all important information.

Then you can do this in your CMakeLists.txt:

```cmake
add_executable(my-project main.cpp)

find_package(test-utils CONFIG PATHS <path-to-binary-dir-of-test-utils>)
# alternatively assuming that the "test-utils_DIR" variable is set: find_package(test-utils CONFIG)

# you can also query (or force specific version during the previous "find_package()" call)
message(STATUS "Found version of test-utils is: ${test-utils_VERSION}")

# this will import search paths, compile definitions and other dependencies of the test-utils as well
target_link_libraries(my-project burda::test-utils)
# or with public visibility: target_link_libraries("my-project" PUBLIC burda::test-utils)

```

### 2. Manual Way
Not recommended.

Make sure that the `include` directory is in the search paths.

You also have to set C++14 standard and potentially other settings as well.

## Examples
For full examples, see implementation of [tests](tests/unit).

### [array.hpp](include/test_utils/array.hpp)
Test implemented at: [array_test.cpp](tests/unit/src/array_test.cpp)
```cpp
#include <test_utils/array.hpp>

const int array1[] = { 1, 2, 3 };
const int array2[] = { 1, 2, 3 };

BURDA_TEST_UTILS_ARRAY_EXPECT_EQUAL(array1, array2, 3);
BURDA_TEST_UTILS_ARRAY_ASSERT_EQUAL(array1, array2, 3);
```

### [lifetime.hpp](include/test_utils/lifetime.hpp)
Test implemented at: [lifetime_test.cpp](tests/unit/src/lifetime_test.cpp)
```cpp
#include <test_utils/lifetime.hpp>

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
burda::test_utils::lifetime::assert_construction_and_destruction<Foo>();
burda::test_utils::lifetime::assert_construction_and_destruction<Foo>("bar", 1.0f);
```

### [make_all_members_public.hpp](include/test_utils/make_all_members_public.hpp)
Test implemented at: [make_all_members_public_test.cpp](tests/unit/src/make_all_members_public_test.cpp)
```cpp
#include <test_utils/make_all_members_public.hpp>

// from now, everything marked either "private" or "protected" becomes "public",
// as marked in the header itself, use at own risk, this is UB in C++

class foo
{
private:
    bool bar = false;
}

// this is compile-able now:
foo f;
f.bar = true;
```

### [mutex.hpp](include/test_utils/mutex.hpp)
Test implemented at: [mutex_test.cpp](tests/unit/src/mutex_test.cpp)
```cpp
#include <test_utils/mutex.hpp>

std::mutex lock;

// calls EXPECT_EQ gtest macros inside, should pass
test_utils::mutex::check_if_owned(lock, false);

lock.lock();

// this should pass as well
test_utils::mutex::check_if_owned(lock, true);
```

### [statics.hpp](include/test_utils/statics.hpp)
Test implemented at: [statics_test.cpp](tests/unit/src/statics_test.cpp)
```cpp
#include <test_utils/statics.hpp>

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
burda::test_utils::statics::assert_default_constructibility<some_struct, true>();
// "some_struct" should be copy constructible
burda::test_utils::statics::assert_copy_constructibility<some_struct, true>();
// "some_struct" should not be move constructible
burda::test_utils::statics::assert_move_constructibility<some_struct, false>();
```

### [time.hpp](include/test_utils/time.hpp)
Test implemented at: [time_test.cpp](tests/unit/src/time_test.cpp)
```cpp
#include <test_utils/time.hpp>

// calls test macros "ASSERT_GE" and "ASSERT_LE" in its implementation
burda::test_utils::time::assert_that_elapsed_time_in_tolerance(7s, 5s, 9s);
```

### [xor.hpp](include/test_utils/xor.hpp)
Test implemented at: [xor_test.cpp](tests/unit/src/xor_test.cpp)
```cpp
#include <test_utils/macros.hpp>

// can use EXPECT or ASSERT version of macro
BURDA_TEST_UTILS_XOR_EXPECT(true, false);
BURDA_TEST_UTILS_XOR_EXPECT(1, 0);
BURDA_TEST_UTILS_XOR_EXPECT(-99, 7);

BURDA_TEST_UTILS_XOR_ASSERT(false, true);
```

## Unit Tests
Tests require sub-module [cmake-helpers](https://github.com/karel-burda/cmake-helpers).

For building tests, run CMake in the source directory [tests/unit](tests/unit):

```cmake
cmake -Bbuild -H.

# you can also add coverage by appending "-DCOVERAGE:BOOL=ON"
cmake -Bbuild/tests/unit -Htests/unit -Dtest-utils_DIR:PATH=$(pwd)/build -DCMAKE_BUILD_TYPE:STRING=RelWithDebInfo
cmake --build build/tests/unit --config RelWithDebInfo

# this runs target "run-all-tests-verbose" that will also run the tests with timeout, etc.:
cmake --build build/tests/unit --target run-all-tests-verbose --config RelWithDebInfo
# or you can execute tests manually
```

For more info, see [.travis.yml](.travis.yml).

## Continuous Integration
Continuous Integration is now being run Linux, OS X and Windows on Travis: https://travis-ci.org/karel-burda/test-utils.

Compilers are set-up to treat warnings as errors and with pedantic warning level.
Targets are built in one stage with debug symbols with code coverage measure and in release mode with debug symbols in the second one.

The project is using these jobs:
  * `test-utils, tests -- linux, debug, cppcheck, coverage, g++, 64-bit`
  * `test-utils, tests -- osx, release with debug info, clang++, 64-bit`
  * `test-utils, tests -- windows, release, msvc, 32-bit`

Project uses [codecov.io](https://codecov.io/gh/karel-burda/test-utils) for code coverage summary.
