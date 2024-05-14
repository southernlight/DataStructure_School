#include <bits/stdc++.h>
using namespace std;
template <class T> class DblList;
class Number
{
  public:
    Number();
    Number(int n);
    void ShowData();
    Number *operator->();
    Number &operator*();
    operator int() const
    {
        return num;
    }

  private:
    int num;
};

template <class T> class DblListNode
{
    friend class DblList<T>;

  public:
    DblListNode();
    DblListNode(const T &newData);

  private:
    T data;
    DblListNode *left, *right;
};

template <class T> class DblList
{
  public:
    class ChainIterator
    {
      public:
        ChainIterator()
        {
            current = new DblListNode<T>;
        }
        ChainIterator(DblListNode<T> *node) : current(node)
        {
        }
        ChainIterator &operator++()
        {
            current = current->right;
            return *this;
        }
        ChainIterator &operator--()
        {
            current = current->left;
            return *this;
        }

        T operator*()
        {
            return current->data;
        }

        bool operator!=(const ChainIterator &other)
        {
            return current != other.current;
        }
        bool operator==(const ChainIterator &other)
        {
            return current == other.current;
        }
        DblListNode<T> *operator&()
        {
            return current;
        }

      private:
        DblListNode<T> *current;
    };
    DblList();
    ~DblList();
    ChainIterator begin();
    ChainIterator end();
    void Insert(int index, T input);
    void Delete(int i);

  private:
    DblListNode<T> *first;
};
DblList<Number> L;
int main()
{

    // 테스트 방법1
    for (int i = 1; i <= 9; i++)
        L.Insert(i - 1, Number(i));
    // 테스트 방법2
    for (DblList<Number>::ChainIterator cur = L.begin(); cur != L.end(); ++cur)
        (*cur).ShowData();
    cout << '\n';
    // 테스트 방법3
    L.Insert(2, Number(100));
    // 테스트 방법4
    for (DblList<Number>::ChainIterator cur = L.begin(); cur != L.end(); ++cur)
        (*cur).ShowData();
    cout << '\n';
    // 테스트 방법5
    L.Delete(6);
    // 테스트 방법6
    for (DblList<Number>::ChainIterator cur = L.begin(); cur != L.end(); ++cur)
        (*cur).ShowData();
    cout << '\n';
    // 테스트 방법7
    int sum = accumulate(L.begin(), L.end(), 0);
    cout << sum << '\n';
    // 테스트 방법8
    DblList<Number>::ChainIterator cur = L.end();
    --cur;
    for (cur; cur != L.end(); --cur)
        (*cur).ShowData();
    cout << '\n';
    return 0;
}

Number::Number() : num(0)
{
}
Number::Number(int n) : num(n)
{
}
void Number::ShowData()
{
    cout << num << " ";
}
Number *Number::operator->()
{
    return this;
}
Number &Number::operator*()
{
    return *this;
}

template <class T> DblListNode<T>::DblListNode() : data(0), left(nullptr), right(nullptr)
{
}
template <class T> DblListNode<T>::DblListNode(const T &newdata) : data(newdata), left(nullptr), right(nullptr)
{
}

template <class T> DblList<T>::DblList()
{
    first = new DblListNode<T>;
    first->left = first;
    first->right = first;
}
template <class T> DblList<T>::~DblList()
{
    DblListNode<T> *p = first->right;
    while (p != first)
    {
        DblListNode<T> *q = p;
        p = p->right;
        delete q;
    }
    delete first;
}
template <class T> typename DblList<T>::ChainIterator DblList<T>::begin()
{
    return ChainIterator(first->right);
}

template <class T> typename DblList<T>::ChainIterator DblList<T>::end()
{
    return ChainIterator(first);
}
template <class T> void DblList<T>::Insert(int index, T input)
{
    DblListNode<T> *newNode = new DblListNode<T>(input);

    DblListNode<T> *p = first->right;
    for (int i = 0; i < index && p->right != first; i++)
    {
        p = p->right;
    }

    newNode->right = p->right;
    newNode->left = p;
    p->right->left = newNode;
    p->right = newNode;
}
template <class T> void DblList<T>::Delete(int index)
{
    DblListNode<T> *p = first->right;
    for (int i = 0; i < index && p->right != first; i++)
    {
        p = p->right;
    }
    p->left->right = p->right;
    p->right->left = p->left;
    delete p;
}
