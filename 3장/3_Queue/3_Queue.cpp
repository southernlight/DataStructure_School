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

template <class T> class Queue
{
  private:
    T *queue;
    int front;
    int rear;
    int capacity;

  public:
    Queue(int queueCapacity);
    bool IsEmpty();
    T &Front();
    T &Rear();
    void Push(const T &x);
    void Pop();
};

template <class T> Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity)
{
    if (capacity < 1)
        throw "Queue capacity must be > 0";
    queue = new T[capacity];
    front = 0;
    rear = 0;
}

template <class T> inline bool Queue<T>::IsEmpty()
{
    return front == rear;
}

template <class T> inline T &Queue<T>::Front()
{
    if (IsEmpty())
        throw "Queue is empty. No front element";
    return queue[(front + 1) % capacity];
}

template <class T> inline T &Queue<T>::Rear()
{
    if (IsEmpty())
        throw "Queue is empty. No rear element";
    return queue[rear];
}

template <class T> void Queue<T>::Push(const T &x)
{
    if ((rear + 1) % capacity == front)
    {
        T *newQueue = new T[2 * capacity];

        int start = (front + 1) % capacity;
        if (start < 2)
        {
            copy(queue + start, queue + start + capacity - 1, newQueue);
        }
        else
        {
            copy(queue + start, queue + capacity, newQueue);
            copy(queue, queue + rear + 1, newQueue + capacity - start);
        }

        front = 2 * capacity - 1;
        rear = capacity - 2;
        capacity *= 2;
        delete[] queue;
        queue = newQueue;
    }

    rear = (rear + 1) % capacity;
    queue[rear] = x;
}
template <class T> void Queue<T>::Pop()
{
    if (isEmpty())
        throw "Queue is empty: Cannot Pop";
    front = (front + 1) % capacity;
    queue[front].~T();
}

int main()
{

    return 0;
}