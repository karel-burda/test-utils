![Version](https://img.shields.io/badge/version-0.5.0-green.svg)
[![License](https://img.shields.io/badge/license-MIT_License-green.svg?style=flat)](LICENSE)
[![Build Status](https://travis-ci.org/karel-burda/test-utils.svg?branch=develop)](https://travis-ci.org/karel-burda/cmake-helpers)

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

Tests are being run in the Continuous Integration environment.
