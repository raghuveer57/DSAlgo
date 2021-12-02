#include <iostream>
#include "../Utils/Utils.h"
#include <unordered_set>
using namespace std;

// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: true
// Example 2:

// Input: nums = [1,2,3,4]
// Output: false
// Example 3:

// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true

// Constraints:

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109

// TC : O(n), SC: O(n)
// An alternate soultion with TC: O(nlogn) and O(1) is to use sorting approach.
bool ContainsDuplicate(int* a, int size)
{
    unordered_set<int> elements;
    bool found = false;

    // use hashmap to determine the duplicates
    for ( int i = 0; i < size; i++)
    {
        if(elements.find(a[i]) == elements.end())
            elements.insert(a[i]);
        else
        {
            found = true;
            break;
        }
    }
    return found;
}

int main(int argc, char *argv[])
{
    int a[] = {1,2,3,1};
    string result = (ContainsDuplicate(a, sizeof(a)/sizeof(a[0]))) ? "Duplicates Found" : "No duplicates" ;
    cout << result << endl;
}