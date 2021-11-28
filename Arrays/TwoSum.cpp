#include <iostream>
#include "../Utils/Utils.h"
#include <unordered_map>
using namespace std;


// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Output: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:
// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Example 3:
// Input: nums = [3,3], target = 6
// Output: [0,1]

int* TwoSum(int* a, int size, int target)
{
    int* result = new int[2]();

    // compilment value is the key and index is the value
    unordered_map<int,int> m;

    for(int i = 0; i < size; i++)
    {
        if(m.count(a[i]) == 0)
            m[target - a[i]] = i; // store the compliment value
        else
        {
            //solution is found
            result[0] = m[a[i]];
            result[1] = i;
        }
    }
    return result;
}

int main(int argc, char *argv[])
{
    int a[] = {3,3};
    int target = 6;
    int* p =  TwoSum(a, sizeof(a)/sizeof(a[0]),target);
    PrintArray(p,2);
    delete [] p;
}