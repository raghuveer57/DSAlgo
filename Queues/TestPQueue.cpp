#include <iostream>
#include "../Utils/PriorityQueue.h"

using namespace std;

int main(int argc, char *argv[])
{
    PriorityQueue<int> queue;
    for ( int i = 7; i >= 1; i--)
    {
        queue.insert(i);
    }
    queue.print();
    //queue.remove(1);
    queue.changePriority(1,9);
    queue.print();
    return 0;
}