cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(test-utils VERSION 0.7.0 LANGUAGES CXX)

include("cmake-helpers/cmake-helpers/messages.cmake")
include("cmake-helpers/cmake-helpers/standard-settings.cmake")

option(UNIT-TESTS "Build with unit tests" OFF)

_print_project_version()

_set_standards("11" "14")
_set_default_build_type("Debug")

set(HEADERS
    include/test_utils/make_all_members_public.hpp
    include/test_utils/static_class_assertions.hpp
    include/test_utils/test_utils.hpp
    include/test_utils/time_utils.hpp)

set(OTHER
    README.md
    .travis.yml
    ${PROJECT_NAME}-config.cmake.in)

add_custom_target(${PROJECT_NAME} SOURCES ${HEADERS} ${OTHER})

configure_file(${PROJECT_NAME}-config.cmake.in "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake" @ONLY)

if (UNIT-TESTS)
    add_subdirectory(tests/unit)
endif()