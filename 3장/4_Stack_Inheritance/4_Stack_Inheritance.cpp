#include <iostream>

using namespace std;
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T> void ChangeSize1D(T *&a, const int oldSize, const int newSize)
{
    if (newSize < 0)
        throw "New length must be >=0";
    T *temp = new T[newSize];
    int number = min(oldSize, newSize);
    copy(a, a + number, temp);
    delete[] a;
    a = temp;
}

template <class T> class Bag
{
  public:
    Bag(int bagCapacity = 10);
    virtual ~Bag();

    virtual int Size() const; // const 가 뒤에 붙으면 멤버변수를 못 바꿔주는 함수이다.
    virtual bool IsEmpty() const;
    virtual T &Element() const; //반환형이 참조형인 경우: 반환받는 변수가 원본이다.
    virtual void Push(const T &x);
    virtual void Pop();

  protected:
    T *array;
    int capacity;
    int top;
};

template <class T> Bag<T>::Bag(int bagCapacity) : capacity(bagCapacity)
{
    if (capacity < 1)
        throw "Capacity must be >0";
    array = new int[capacity];
    top = -1;
}
template <class T> Bag<T>::~Bag()
{
    delete[] array;
}
template <class T> inline int Bag<T>::Size() const
{
    return top + 1;
}

template <class T> inline bool Bag<T>::IsEmpty() const
{
    return Size() == 0;
}

template <class T> inline T &Bag<T>::Element() const
{
    if (IsEmpty())
        throw "Bag is empty.";
    return array[rand() % Size()];
}

template <class T> void Bag<T>::Push(const T &x)
{
    if (capacity == top + 1)
        ChangeSize1D(array, capacity, 2 * capacity);
    capacity *= 2;
    array[++top] = x;
}

template <class T> void Bag<T>::Pop()
{
    if (IsEmpty())
        throw "Bag is empty, cannot delete";
    int deletePos = rand() % Size();
    copy(array + deletePos + 1, array + top + 1, array + deletePos);
    top--;
}

template <class T> class Stack : public Bag<T>
{
  public:
    Stack(int stackCapacity = 10);
    ~Stack();
    int Top() const;
    void Pop();
};

template <class T> Stack<T>::Stack(int stackCapacity) : Bag<T>(stackCapacity)
{
    ;
}

template <class T> Stack<T>::~Stack()
{
}

template <class T> int Stack<T>::Top() const
{
    if (this->IsEmpty())
        throw "Stack is empty";
    return this->array[this->top];
}

template <class T> void Stack<T>::Pop()
{
    if (this->IsEmpty())
        throw "Stack is empty. Cannot delete";
    this->top--;
}

int main()
{

    return 0;
}