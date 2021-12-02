#include<iostream>
using namespace std;

// subscript operator should be overloaded here
// TODO: need to make this generic by probably using something size of (T)
template <typename T>
void ReverseArray(T p[], int first, int last, int size)
{
    if( first < 0 || last >= size || first > last )
    {
        cout << "Incorrect postions given in the function ReverseArray" << endl;
        return;
    }

    while(first < last)
    {
        swap(p[first],p[last]);
        first++;
        last--;
    }
}

// subscript operator should be overloaded here
// TODO: need to make this generic by probably using something size of (T)
template <typename T>
void PrintArray(T p[], int size)
{
    for( int i = 0; i < size; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
}

template <typename T>
void PrintArray(T p[], int size, int start, int end)
{
    if( start >= size || end >= size)
    {
        cout << "Indexing is not correct" << endl;
        return;
    }
    for( int i = start; i <= end; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
}

template <typename T>
void swap(T &a , T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void SayHello()
{
    cout << "Hello " << "World!" << endl;
}