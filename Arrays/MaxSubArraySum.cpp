#include <iostream>
#include "../Utils/Utils.h"
#include <unordered_map>
using namespace std;


// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

// A subarray is a contiguous part of an array.

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
// Example 2:

// Input: nums = [1]
// Output: 1
// Example 3:

// Input: nums = [5,4,-1,7,8]
// Output: 23
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
 

// Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

int MaxSubArraySum(int* a, int size)
{
    /* Solution: Kadane's Algorithm
     There are two main steps involved in solving this problem
     1. compare the accumulated sum with the current value and use the max value 
     2. compare the sum parts with the max sum and update it when applicable
    */
    
    int cur_max_sum = a[0];
    int all_time_max_sum = a[0];
    int start = 0;
    int end = 0;
    for(int i = 1; i < size; i++)
    {
        if( a[i] > cur_max_sum + a[i])
            start = i;
        cur_max_sum = max(a[i],cur_max_sum + a[i]); // compare the accumulated sum with the current value
        if( cur_max_sum > all_time_max_sum)
            end = i;
        all_time_max_sum = max(cur_max_sum,all_time_max_sum); // compare the sum parts with the max sum and update it when applicable
    }
    PrintArray(a,size,start,end);
    return all_time_max_sum;
}

int main(int argc, char *argv[])
{
    int a[] = {5,4,-1,7,8};
    int p =  MaxSubArraySum(a, sizeof(a)/sizeof(a[0]));
    cout << "Max sum is " << p << endl;
}