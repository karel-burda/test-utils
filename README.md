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
