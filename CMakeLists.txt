﻿# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)
add_compile_options(-std=c++11)

project ("MiscProblems")

# Include sub-projects.
add_subdirectory ("AdHocProblems")
add_subdirectory("Arrays")
add_subdirectory("LinkedLists")
add_subdirectory("Queues")
add_subdirectory("Trees")
add_subdirectory("Matrix")

