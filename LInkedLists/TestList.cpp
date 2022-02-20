#include <iostream>
#include "../Utils/LinkedList.h"

using namespace std;

int main(int argc, char *argv[])
{
    LinkedList<int> list;
    list.pushFront(3);
    list.pushFront(4);
    list.pushBack(5);
    list.insert(5,6);
    list.pushBack(7);
    list.printList();
    list.remove(5);
    list.printList();
    list.remove(4);
    list.printList();
    list.remove(7);
    list.printList();
    list.remove(6);
    list.printList();
    list.remove(30);
    list.remove(3);
    list.printList();
    return 0;
}