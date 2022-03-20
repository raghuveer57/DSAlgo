# CMakeList.txt : CMake project for MiscProblems, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (ReverseArray "ReverseArray.cpp")
add_executable (MergeSortedArrays "MergeSortedArrays.cpp")
add_executable(TwoSum "TwoSum.cpp")
add_executable(MaxSubArraySum "MaxSubArraySum.cpp")
add_executable(MoveZeros "MoveZeros.cpp")
add_executable(ContainsDuplicate "ContainsDuplicate.cpp")
add_executable(LongestWord "LongestWord.cpp")
add_executable(RearrangeArray "RearrangeArray.cpp")
add_executable(SearchRotatedSortedArray "SearchRotatedSortedArray.cpp" "../Utils/Utils.h")
# TODO: Add tests and install targets if needed.
