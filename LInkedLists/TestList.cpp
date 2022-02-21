#include <iostream>
#include "../Utils/LinkedList.h"
#include "../Utils/DoublyLinkedList.h"

using namespace std;

int main(int argc, char *argv[])
{
    //LinkedList<int> list;
    DoublyLinkedList<int> list;
    list.pushFront(3);
    list.pushFront(4);
    list.pushBack(5);
    list.insert(4,6);
    list.printList();
    list.printList(false);
    list.remove(5);
    list.printList();
    list.printList(false);
    list.remove(4);
    list.printList();
    list.printList(false);
    list.remove(7);
    list.printList();
    list.printList(false);
    list.remove(6);
    list.printList();
    list.printList(false);
    list.remove(3);
    list.printList();
    return 0;
}