#include <iostream>
template <class InputIt, class OutputIt> OutputIt copy(InputIt first, InputIt last, OutputIt d_first)
{
    while (first != last)
    {
        *d_first++ = *first++;
    }
    return d_first;
}

int main()
{
    return 0;
}