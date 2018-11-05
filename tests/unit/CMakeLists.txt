cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(tests LANGUAGES CXX)

message(STATUS "Building unit tests")

include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake-helpers/cmake-helpers/coverage.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake-helpers/cmake-helpers/gtest.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake-helpers/cmake-helpers/warnings.cmake)

add_executable(${PROJECT_NAME} "")

target_sources(
    ${PROJECT_NAME}
        PUBLIC
            src/make_all_members_public_test.cpp
            src/static_class_assertions_test.cpp
            src/test_utils_test.cpp
            src/time_utils_test.cpp)


find_package(test-utils CONFIG HINTS ${CMAKE_BINARY_DIR}/../.. REQUIRED)
target_link_libraries(${PROJECT_NAME} burda::test-utils)

_gtest_bootstrap_and_link(${PROJECT_NAME} "release-1.8.1" "Release")

if (COVERAGE)
    message(STATUS "Building unit tests with code coverage")

    _coverage_add_build_options(${PROJECT_NAME})
endif()

enable_testing()

add_test(NAME all-unit-tests
         WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
         COMMAND $<TARGET_FILE:${PROJECT_NAME}> --gtest_color=yes --gtest_shuffle)

add_custom_target(run-all-tests-verbose
                    COMMAND ${CMAKE_CTEST_COMMAND} -V -C ${CMAKE_BUILD_TYPE} --build-run-dir ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} --timeout 300
                    DEPENDS ${PROJECT_NAME})

_warnings_add_pedantic_level(${PROJECT_NAME})
_warnings_suppress(${PROJECT_NAME} "keyword-macro")
