#ifndef LINKEDLISTSTACK_H
#define LINKEDLISTSTACK_H

#include <iostream>
using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *top;

public:
    LinkedList() : top(nullptr) {}

    void push(int n)
    {
        Node *temp = new Node();
        temp->data = n;
        temp->next = top;
        top = temp;
    }

    int pop()
    {
        if (top == nullptr)
        {
            cout << "Underflow" << endl;
            return -1;
        }
        int poppedValue = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    int peek()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool isempty()
    {
        return top == nullptr;
    }

    void display()
    {
        Node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

#endif
