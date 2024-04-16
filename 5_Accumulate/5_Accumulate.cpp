#include <iostream>

template <class OP> int accumulate(int *start, int *end, int initialValue, OP operation)
{
    int result = initialValue;
    while (start != end)
    {
        result = operation(result, *(start++));
    }

    return result;
}
template <typename T> struct plus
{
    T operator()(const T &x, const T &y)
    {
        return x + y;
    }
};
template <typename T> struct multiplies
{
    T operator()(const T &x, const T &y)
    {
        return x * y;
    }
};

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = accumulate(arr, arr + 10, 0, plus<int>());
    int product = accumulate(arr, arr + 10, 1, multiplies<int>());
    std::cout << "Sum : " << sum << std::endl;
    std::cout << "Product : " << product << std::endl;

    return 0;
}