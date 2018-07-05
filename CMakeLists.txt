cmake_minimum_required(VERSION 2.8)
project(LeetCode)
set (SRC_VERSION_MAJOR 1)
set (SRC_VERSION_MINOR 0)
set (SRC_VERSION_PATCH 1)
set (SRC_VERSION ${SRC_VERSION_MAJOR}.${SRC_VERSION_MINOR}.${SRC_VERSION_PATCH})
set (PROJECT_VERSION "${SRC_VERSION}")

# IF (CMAKE_SYSTEM_NAME MATCHES "Windows")

# ELSE()
#     SET (CMAKE_C_COMPILER             "/usr/bin/clang")
#     SET (CMAKE_CXX_COMPILER             "/usr/bin/clang++")
# ENDIF()

add_compile_options(-std=c++11)

add_subdirectory(Array)
add_subdirectory(DP)
add_subdirectory(HashTable)
add_subdirectory(LinkedList)
add_subdirectory(Math)
add_subdirectory(Other)
add_subdirectory(Stack)
add_subdirectory(String)
add_subdirectory(Tree)
add_subdirectory(Search)
add_subdirectory(Bitset)

