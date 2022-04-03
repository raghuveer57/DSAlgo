#include <iostream>
#include "../Utils/LinkedList.h"

using namespace std;

// function to create a list
void createList(LinkedList<int> &list)
{
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushBack(5);
}

int main()
{
    LinkedList<int> list;
    createList(list);
    list.printList();
    list.reverseList();
    list.printList();
}

