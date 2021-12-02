#include <iostream>
#include "../Utils/Utils.h"
#include <unordered_map>
using namespace std;


// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]

// Constraints:

// 1 <= nums.length <= 104
// -231 <= nums[i] <= 231 - 1

// Follow up: Could you minimize the total number of operations done?


// TC : O(n), SC: O(1)
void MoveZeros(int* a, int size)
{
    // Technique is to use two indexes inside a single for loop
    int count = 0;

    //First loop is for reading the array and storing the non zero values in the 
    // same error using second index 'count'
    for ( int i = 0; i < size; i++)
    {
        if(a[i]!=0)
            a[count++] = a[i];
    }

    // since all the non-zero elements are collected at the front fill all the remaining places with zeros
    for ( int i = count; i  < size; i++)
        a[i] = 0;
}

int main(int argc, char *argv[])
{
    int a[] = {0,1,0,3,12};
    MoveZeros(a, sizeof(a)/sizeof(a[0]));
    PrintArray(a,sizeof(a)/sizeof(a[0]));
}