#pragma once
#include <iostream>
#include "Utils.h"
#include <cmath>
using namespace std;

template <typename T>
class PriorityQueue
{
private:
    int size;
    T H[50]; // pre allocated max heap size
    bool isMin;

public:
    // By default the max head is generated
    PriorityQueue() : size(-1),isMin(false) {}
    // min = true, max = false
    PriorityQueue(bool min) : size(-1),isMin(min) {}
    ~PriorityQueue() {}

    // method to return parent when the index is given
    int parent(int i)
    {
        return (i - 1) / 2;
    }

    // method to return left child when index is given
    int leftChild(int i)
    {
        return ((2 * i) + 1);
    }

    //method to return right child when index is given
    int rightChild(int i)
    {
        return ((2 * i) + 2);
    }

    //shift the value to the top of the tree
    void shiftUp(int i)
    {
        // the value is compared with the parent and then 
        // swapped if it is less. 
        // index is moved to parent if the swap happens.
        while (i > 0 && H[parent(i)] < H[i])
        {
            swap(H[parent(i)], H[i]);
            i = parent(i);
        }
    }

    //shift the value to the bottom of the tree
    void shiftDown(int i)
    {
        int maxIndex = i;
        
        // Check if the element falls below left 
        // or the right child. Checks should be 
        // performed in order to preseve the correct order
        int l = leftChild(i);
        if (l <= size && H[l] > H[maxIndex])
            maxIndex = l;

        int r = rightChild(i);
        if (r <= size && H[r] > H[maxIndex])
            maxIndex = r;

        // condition to stop the recursion if there are no 
        // applicable left/right childs.
        if (i != maxIndex)
        {
            swap(H[i], H[maxIndex]);
            shiftDown(H[maxIndex]);
        }
    }

    // insert the data to the last postion
    // and shift up to the desired place
    void insert(T p)
    {
        size = size+ 1;
        H[size] = p; 
        
        shiftUp(size);
    }

    // store the top value
    // swap first and last value in the array
    // decrement size
    // shiftdown the swapped least value to the correct location
    T extractMax()
    {
        T max = H[0];
        swap(H[0], H[size]);
        --size;
        // shift down the swapped value as per heap prop
        shiftDown(0);
        return max;
    }

    // change the value 
    // use shift up / shift down based on the value check.
    void changePriority(int i, T p)
    {
        T old = H[i];
        H[i] = p;
        (old > p) ? shiftDown(i) : shiftUp(i);
    }

    T getMax()
    {
        return H[0];
    }

    void remove(int i)
    {
        H[i] = getMax() + 1;
        shiftUp(i);
        extractMax();
    }

    void print()
    {
        int levels = 1 + floor(log2(size + 1));
        int start = 0, end = 0;
        for ( int i = 1; i <= levels; i++)
        {
            end = start + (pow(2,i-1)-1);
            if( end > size)
                end = size;
            PrintArray(H,start,end);
            start = end + 1;
        }
    }
};