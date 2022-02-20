#pragma once
#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(T dat) : data(dat), next(nullptr) {}
        Node(T dat, Node *nex) : data(dat), next(nex) {}
    };
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList()
    { // Delete the nodes when the linked list goes out of scope
        deleteNodes();
    }
    
    void deleteNodes()
    {
        if (!head)
            return;
        do
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        } while (head != nullptr);
    }

    void pushBack(T data)
    { // TC: O(n)
        if (!head)
            head = new Node(data);
        else
        {
            Node *temp = new Node(data);
            Node *end = head;
            while (end->next != nullptr)
            {
                end = end->next;
            }
            end->next = temp;
        }
    }

    void pushFront(T data)
    { // TC: O(1)
        if (!head)
            head = new Node(data);
        else
        {
            Node *temp = new Node(data, head);
            head = temp;
        }
    }

    void insert(T prevdata, T insertData)
    { // insert after the given data TC: O(n)
        Node *temp = head;
        while (temp && temp->data != prevdata)
        {
            temp = temp->next;
        }
        if (!temp)
            cout << "Insertion failed. Data: " << prevdata << " not found" << endl;
        else
        {
            insert(insertData, temp);
        }
    }

    void insert(T data, Node *current)
    { // insert data when the prev node is given
        Node *node = new Node(data, current->next);
        current->next = node;
    }

    void remove(Node *prev, Node *current)
    { // current node should be deleted
        if (!prev)
            head = head->next;
        else
            prev->next = current->next;
        delete current;
    }

    void remove(T data)
    {
        if (!head)
        {
            cout << "Cannot delete from an empty list" << endl;
            return;
        }
        else
        {
            Node *current = head;
            Node *previous = nullptr;
            while (current && data != current->data)
            {
                previous = current;
                current = current->next;
            }
            if (!current)
                cout << "Cannot Delete. Data not found" << endl;
            else
            {
                remove(previous, current);
            }
        }
    }

    void printList()
    {
        if (!head)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        cout << head->data << " ";
        while (temp->next != nullptr)
        {
            temp = temp->next;
            cout << temp->data << " ";
        } 
        cout << endl;
    }
};