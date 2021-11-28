#include <iostream>
#include "../Utils/Utils.h"
using namespace std;

// TC : O(n), SC : O(1)
void mergeArray(int a1[], int a2[], int size1, int size2, int a3[])
{
    int i = 0;
    int j = 0;

    //compare the elements and fill the array
    while ( (i < size1) && (i < size2))
    {
        if(a1[i] < a2[j])
        {
            a3[i+j] = a1[i];
            i++;
        }
        else if (a1[i] >= a2[j])
        {
            a3[i+j] = a2[j];
            j++;
        }
        // equality check needs to be handled additionally to merge the duplicates if specified.
    }

    // For the remaining elements after the comparison
    while( i < size1)
    {
        a3[i+j] = a1[i];
        i++;
    }

    while ( j < size2)
    {
        a3[i+j] = a2[j];
        j++;
    }
}

int main(int argc, char *argv[])
{
    int a1[] = {1,3,5,7,9};
    int a2[] = {2,4,6,8,50};
    int a3[10];  // create an empty array of combined length
    mergeArray(a1,a2,5,5,a3);
    PrintArray(a3,10);
}