#ifndef DYNINTSTACK_H
#define DYNINTSTACK_H

class DynIntStack
{
private:
   class StackNode
   {
      friend class DynIntStack;
      int value;
      StackNode *next;
      // Constructor
      StackNode(int value1, StackNode *next1 = nullptr)
       {
         value = value1;
         next = next1;
       }
   };
   StackNode *top;
public:
   DynIntStack() { top = nullptr; }
   void push(int);
   void pop(int &);
   bool isEmpty() const;
};	
#endif