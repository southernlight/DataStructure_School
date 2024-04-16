#include <iostream>
template <class BidirIt> bool next_permutation(BidirIt first, BidirIt last)
{
    if (first == last) //범위는 1~3과 같아야하는데, 만약 범위를 1~1이라고 하면 잘못이기 때문에 false return
        std::cout << "hello1";
    BidirIt i = last;
    while (true)
    {
        BidirIt i1, i2;
        i1 = i;
        if (*--i < *i1)
        {
            i2 = last;
            while (i < i2)
            {
                int k;
            }
        }
    }
}
void swap(int &p, int &q);

int main()
{
    int arr[2] = {1, 2};
    next_permutation(arr, arr + 1);

    return 0;
}

void swap(int &p, int &q)
{
    int temp = p;
    p = q;
    q = temp;
}
