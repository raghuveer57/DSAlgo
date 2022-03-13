# CMakeList.txt : CMake project for MiscProblems, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
add_compile_options(-std=c++11)

# Add source to this project's executable.
add_executable (Traversals "Traversals.cpp" "../Utils/BinaryTree.h")

# TODO: Add tests and install targets if needed.
