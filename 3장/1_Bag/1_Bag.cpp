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
    ~Bag();

    int Size() const; // const 가 뒤에 붙으면 멤버변수를 못 바꿔주는 함수이다.
    bool IsEmpty() const;
    T &Element() const; //반환형이 참조형인 경우: 반환받는 변수가 원본이다.
    void Push(const T &x);
    void Pop();

  private:
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

int main()
{
    Bag<int> a;
    a.Push(7);
    int b = a.Element();
    cout << b;

    return 0;
}