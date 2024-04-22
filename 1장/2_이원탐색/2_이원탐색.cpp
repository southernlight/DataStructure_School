#include <iostream>

using namespace std;
int BinarySearch(int *array, int n);
int main()
{
    int array[7] = {2, 3, 4, 5, 7, 8, 9};
    int n = 7;
    int index = BinarySearch(array, 3);

    return 0;
}

int BinarySearch(int *array, int n)
{
    int size = sizeof(array) / sizeof(int);
    int left = 0;
    int right = size - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (array[mid] == n)
            return mid;
        else if (array[mid] > n)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}