cmake_minimum_required(VERSION 3.14)
project(UnitTest)

find_package(GTest REQUIRED)
if(NOT GTest)
  # Автоматическая загрузка GoogleTest
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
  )
  FetchContent_MakeAvailable(googletest)
endif()

# Тестовый модуль
set(SRCS ${CMAKE_CURRENT_SOURCE_DIR}/tests.cpp
        ${CMAKE_SOURCE_DIR}/src/compare_trees.cpp
        ${CMAKE_SOURCE_DIR}/../Tree\ from\ array/src/array_tree.cpp
)
add_executable(tests ${SRCS})
target_include_directories(tests PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/../node
    ${CMAKE_SOURCE_DIR}/../Tree\ from\ array/include)

target_compile_features(tests PUBLIC cxx_std_17)

if(NOT GTest)
  target_link_libraries(tests PRIVATE gtest_main)
else()
  target_link_libraries(tests PUBLIC GTest::gtest GTest::gtest_main)
endif()

enable_testing()
add_test(NAME tests COMMAND tests)
