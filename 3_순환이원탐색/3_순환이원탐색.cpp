#include <iostream>

using namespace std;
int RecursionBinarySearch(int *arr, const int x, const int left, const int right);
int main()
{
    int arr[7] = {2, 3, 4, 5, 6, 7, 8};
    int index = RecursionBinarySearch(arr, 3, 0, 6);
    cout << index;
    return 0;
}

int RecursionBinarySearch(int *arr, const int x, const int left, const int right)
{
    if (left <= right)
    {
        int middle = (left + right) / 2;
        if (arr[middle] == x)
            return middle;
        else if (arr[middle] > x)
            return RecursionBinarySearch(arr, x, left, middle - 1);
        else
            return RecursionBinarySearch(arr, x, middle + 1, right);
    }

    return -1;
}