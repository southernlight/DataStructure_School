#include <iostream>

using namespace std;

void SelectionSort(int *a, const int n);
int main()
{
    int array[7] = {9, 3, 2, 7, 8, 4, 5};
    SelectionSort(array, 7);
    for (int i = 0; i < 7; i++)
        cout << array[i] << " ";
    return 0;
}

void SelectionSort(int *a, const int n)
{
    int min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        swap(a[i], a[min]);
    }
}

void swap(int &p, int &q)
{
    int temp = p;
    p = q;
    q = temp;
}