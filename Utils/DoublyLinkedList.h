#pragma once
#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList
{
private:
    struct Node
    {
        T data;
        Node *next, *prev;
        Node(T dat) : data(dat), next(nullptr), prev(nullptr) {}
        Node(T dat, Node *pre, Node *nex) : data(dat), prev(pre), next(nex) {}
    };
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    { // Create dummy head and node and insert every other node in between.
        // This is done for easier implementation
        T data = T();
        head = new Node(data);
        tail = new Node(data, head, nullptr);
        head->next = tail;
    }

    ~DoublyLinkedList()
    { // Delete the nodes when the linked list goes out of scope
        deleteNodes();
    }

    void deleteNodes()
    {
        if (head->next != tail)
        {
            // This would mean that the list is empty
            Node *temp = head->next;
            while (head->next != nullptr)
            {
                Node *temp = head;
                head = head->next;
                // cout << "deleting data: " << temp->data << endl;
                delete temp;
            }
        }
        // cout << "deleting data: " << head->data << endl;
        delete head;
    }

    void pushBack(T data)
    { // TC: O(1)
        Node *temp = tail->prev;
        insert(data, temp, tail);
    }

    void pushFront(T data)
    { // TC: O(1)
        Node *temp = head->next;
        insert(data, head, temp);
    }

    void insert(T data, Node *previous, Node *after)
    { // insert between the to given nodes
        Node *temp = new Node(data, previous, after);
        previous->next = temp;
        after->prev = temp;
    }

    void insert(T prevData, T insertData)
    { // insert after a given data
        Node *temp = head->next;
        while (temp && temp != tail)
        {
            if (prevData == temp->data)
            {
                insert(insertData, temp, temp->next);
                break;
            }
        }
    }

    void remove(Node *current)
    { // current node should be deleted
        if( current == head || current == tail)
        {
            cout << "Cannot remove auxiliary head or tail" << endl;
            return;
        }
        Node* before = current->prev;
        Node* after = current->next;
        before->next = after;
        after->prev = before;
        delete current;
    }

    void remove(T data)
    {
        if (head->next == tail)
        {
            cout << "Cannot delete from an empty list" << endl;
            return;
        }
        else
        {
            Node *current = head->next;
            while (current != tail && data != current->data)
            {
                current = current->next;
            }
            if (!current || current == tail)
                cout << "Cannot Delete. Data not found" << endl;
            else
            {
                remove(current);
            }
        }
    }

    void printList(bool forward = true)
    {
        // Print the list in the forward direction
        if (forward)
        {
            Node *temp = head->next;
            while (temp && temp != tail)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {   //print the list in the reverse direction
            Node * temp = tail->prev;
            while (temp && temp != head)
            {
                cout << temp->data << " ";
                temp = temp->prev;
            }
            cout << endl;
        }
    }
};