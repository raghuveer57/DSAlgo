#include<iostream>
using namespace std;

void ReverseArray(int p[], int first, int last, int size)
{
    if( first < 0 || last >= size || first > last )
        cout << "Incorrect postions given in the function ReverseArray" << endl;

    while(first < last)
    {
        swap(p[first],p[last]);
        first++;
        last--;
    }
    
}

void PrintArray(int p[], int size)
{
    for( int i = 0; i < size; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
}

void swap(int &a , int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void SayHello()
{
    cout << "Hello " << "World!" << endl;
}