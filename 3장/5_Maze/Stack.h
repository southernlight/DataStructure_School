#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template <class T> class Stack
{
  public:
    Stack(int stackCapacity);
    bool IsEmpty() const;
    T &Top() const;
    void Push(const T &x);
    void Pop();
    template <class U> friend ostream &operator<<(ostream &os, Stack<U> &s);

  private:
    T *stack;
    int capacity;
    int top;
};
#endif