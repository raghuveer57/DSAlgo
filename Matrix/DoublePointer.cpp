#include <iostream>
using namespace std;

// Default values are 1......n
int **allocateMatrix(int rows, int columns)
{
    int **arr = new int *[rows]; // rows
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[columns]{++count,++count,++count}; // columns
    }
    return arr;
}

void printMatrix(int **arr, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }
}

int main()
{
    int **arr = allocateMatrix(3,3);
    printMatrix(arr,3,3);
    return 0;
}