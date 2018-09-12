cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(test-utils VERSION 0.5.0 LANGUAGES CXX)

include("cmake-helpers/cmake-helpers/messages.cmake")

option(UNIT-TESTS "Build with unit tests" OFF)

_print_project_version()

set(HEADERS
    include/test-utils/make_all_members_public.hpp
    include/test-utils/static_class_assertions.hpp
    include/test-utils/test_utils.hpp
    include/test-utils/time_utils.hpp)

set(OTHER
    #README.md
    #.travis.yml
    ${PROJECT_NAME}-config.cmake.in)

add_custom_target(${PROJECT_NAME} SOURCES ${HEADERS} ${OTHER})

configure_file(${PROJECT_NAME}-config.cmake.in "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake" @ONLY)
