#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

// Default values are 1......n
int *allocateMatrix(int rows, int columns)
{
    int *arr = new int [rows * columns]; // rows
    for (int i = 0; i < rows * columns; i++)
    {
        arr[i] = i+1;
    }
    return arr;
}

void printMatrix(int *arr, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << arr[i*columns + j] <<" ";
        }
        cout << endl;
    }
}

void transposeMatrix( int *arr, int rows, int columns)
{
    int *b = new int [ rows * columns];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
             b[i*columns + j] = arr[ i + j*rows];
        }
    }
    for (int i = 0; i < rows * columns; i++)
    {
        arr[i] = b[i];
    }
    delete []b;
}

int main()
{
    int *arr = allocateMatrix(3,3);
    printMatrix(arr,3,3);
    transposeMatrix(arr,3,3);
    cout << endl;
    printMatrix(arr,3,3);
    return 0;
}