cmake_minimum_required(VERSION 3.19)

project(subTrees)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -Wpedantic -fsanitize=address,undefined -g -DNDEBUG -O0")

set(src ${CMAKE_SOURCE_DIR}/src/main.cpp
        ${CMAKE_SOURCE_DIR}/src/sub_trees.cpp
        ${CMAKE_SOURCE_DIR}/../Compare\ Trees/src/compare_trees.cpp
        )

set(exec subTrees.out)
add_executable(${exec}
    ${src}
    )
target_compile_features(${exec} PUBLIC cxx_std_17)
target_include_directories(${exec} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(${exec} PUBLIC ${CMAKE_SOURCE_DIR}/../Node)
target_include_directories(${exec} PUBLIC ${CMAKE_SOURCE_DIR}/../Compare\ Trees/include)

include(CTest)
enable_testing()

add_subdirectory(${CMAKE_SOURCE_DIR}/tests)
