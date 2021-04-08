#include "DynTempStack.h"
//#include <iostream>
//#include <cstdlib>
//using namespace std;

////**************************************************
//// Member function push pushes the argument onto   *
//// the stack.                                      *
////**************************************************
//template <class t>
//void DynTempStack<t>::push(t num)
//{
//    top = new StackNode(num, top);
//}
//
////*****************************************************
//// Member function pop removes the value at the top   *
//// of the stack and copies it into the variable       *
//// passed as an argument.                             *
////*****************************************************
//template <class t>
//void DynTempStack<t>::pop(t& num)
//{
//    StackNode* temp;
//
//    if (isEmpty())
//    {
//        cout << "The stack is empty.\n";
//        exit(1);
//    }
//    else   // Pop value off top of stack
//    {
//        num = top->value;
//        temp = top;
//        top = top->next;
//        delete temp;
//    }
//}
//
////*****************************************************
//// Member function isEmpty returns true if the stack  *
//// is empty, or false otherwise.                      *
////*****************************************************
//template <class t>
//bool  DynTempStack<t>::isEmpty() const
//{
//    if (!top)
//        return true;
//    else
//        return false;
//}