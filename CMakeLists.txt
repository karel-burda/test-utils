cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(test-utils VERSION 1.0.2 LANGUAGES CXX)

add_library(${PROJECT_NAME} INTERFACE)

target_sources(${PROJECT_NAME}
                   INTERFACE
                       ${CMAKE_CURRENT_SOURCE_DIR}/include/test_utils/lifetime_assertions.hpp
                       ${CMAKE_CURRENT_SOURCE_DIR}/include/test_utils/make_all_members_public.hpp
                       ${CMAKE_CURRENT_SOURCE_DIR}/include/test_utils/static_class_assertions.hpp
                       ${CMAKE_CURRENT_SOURCE_DIR}/include/test_utils/time.hpp
                       ${CMAKE_CURRENT_SOURCE_DIR}/include/test_utils/macros.hpp)

target_include_directories(${PROJECT_NAME}
                               INTERFACE
                                   ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_features(${PROJECT_NAME}
                            INTERFACE
                                cxx_std_14)

install(TARGETS ${PROJECT_NAME}
        EXPORT _targets)

export(EXPORT _targets
       NAMESPACE burda::
       FILE "${PROJECT_NAME}-config.cmake")

include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
                                 COMPATIBILITY ExactVersion)
