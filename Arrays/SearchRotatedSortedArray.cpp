#include <iostream>
using namespace std;
#include "../Utils/Utils.h"

// returns the index where the sorted array is rotated
int rotatedSortedIndex(int a[], int start, int end)
{
    int rotIndex = -1;

    while (start < end)
    {
        int mid = (start + end) / 2;
        //condition for checking if the 
        //index is rotated
        if (a[mid] > a[mid + 1])
        {
            rotIndex = mid;
            break;
        }
        if (a[start] < a[mid])
            start = mid + 1;
        else
            end = mid;
    }
    return rotIndex;
}

int main(int argc, char *argv[])
{
    int a[] = {5, 6, 7, 8, 9, 1, 2, 3, 4};
    int i = rotatedSortedIndex(a, 0, 8);
    bool result = false;
    int searchElement = 4;
    if (i != -1)
    {
        result = BinarySearchArray(a, searchElement, 0, i);
        if (!result)
            result = BinarySearchArray(a, searchElement, i + 1, 8);
    }
    else
    {
        cout << "Not a sorted rotated array" << endl;
        return 0;
    }
    if (result)
        cout << searchElement << " is found " << endl;
    else
        cout << searchElement << " is not found " << endl;
}
