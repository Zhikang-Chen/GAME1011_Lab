#pragma once
#ifndef DYNTEMPSTACK_H
#define DYNTEMPSTACK_H

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class DynTempStack
{
private:
    class StackNode
    {
        friend class DynTempStack;
        T value;
        StackNode* next;
        // Constructor
        StackNode(T value1, StackNode* next1 = nullptr)
        {
            value = value1;
            next = next1;
        }
    };
    StackNode* top;
public:
    DynTempStack() { top = nullptr; }
    T back()
    {
        if (!isEmpty())
            return top->value;
        else
            return nullptr;
    }
	
    void push(T var)
	{
        top = new StackNode(var, top);
    }
	
    void pop(T&num)
    {
        StackNode* temp;

        if (isEmpty())
        {
            cout << "The stack is empty.\n";
            return;
            //exit(1);
        }
        else   // Pop value off top of stack
        {
            num = top->value;
            temp = top;
            top = top->next;
            delete temp;
        }
    }

    void display()
    {
        auto c = top;
        while (c != nullptr)
        {
            cout << c->value << ", ";
            c = c->next;
        }
        cout << endl;
    }
	
    bool isEmpty() const
    {
        if (top == nullptr)
            return true;
        else
            return false;
    }

};
#endif