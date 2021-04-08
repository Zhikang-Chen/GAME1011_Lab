#pragma once
#ifndef DYNTEMPQUEUE_H
#define DYNTEMPQUEUE_H
#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class DynTempQueue
{
private:
    class QueueNode
    {
        friend class DynTempQueue;
        T value;
        QueueNode* next;
        QueueNode(T value1, QueueNode* next1 = nullptr)
        {
            value = value1;
            next = next1;
        }
    };
    // These track the front and rear of the queue
    QueueNode* front;
    QueueNode* rear;
public:
    // Constructor and Destructor
    DynTempQueue()
    {
        front = nullptr;
        rear = nullptr;
    }
    ~DynTempQueue()
    {
        clear();
    }

    // Member functions
    void enqueue(T num)
    {
        if (isEmpty())
        {
            front = new QueueNode(num);
            rear = front;
        }
        else
        {
            rear->next = new QueueNode(num);
            rear = rear->next;
        }
    }
	
    void dequeue(T& num)
    {
        QueueNode* temp;
        if (isEmpty())
        {
            cout << "The queue is empty.\n";
            return;
            //exit(1);
        }
        else
        {
            num = front->value;
            temp = front;
            front = front->next;
            delete temp;
        }
    }

    void display()
    {
        auto c = front;
        while (c != nullptr)
        {
            cout << c->value << ", ";
            c = c->next;
        }
        cout << endl;
    }
	
    bool isEmpty() const
    {
        if (front == nullptr)
            return true;
        else
            return false;
    }
	
    void clear()
    {
        T value;   // Dummy variable for dequeue
        while (!isEmpty())
            dequeue(value);
    }
};
#endif