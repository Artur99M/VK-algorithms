cmake_minimum_required(VERSION 3.19)

project(completeTree)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -Wpedantic -fsanitize=address,undefined -g -DNDEBUG -O0")

set(src ${CMAKE_SOURCE_DIR}/src/main.cpp
        ${CMAKE_SOURCE_DIR}/src/is_complete_tree.cpp
        )

set(exec completeTree.out)
add_executable(${exec}
    ${src}
    )
target_compile_features(${exec} PUBLIC cxx_std_17)
target_include_directories(${exec} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(${exec} PUBLIC ${CMAKE_SOURCE_DIR}/../Node)

include(CTest)
enable_testing()

add_subdirectory(${CMAKE_SOURCE_DIR}/tests)
