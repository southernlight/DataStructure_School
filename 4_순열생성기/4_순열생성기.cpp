#include <iostream>

using namespace std;

void Permutations(char *a, int start, int end);

int main()
{
    char array[3] = {'A', 'B', 'C'};
    Permutations(array, 0, 2);
    return 0;
}

void Permutations(char *a, int start, int end)
{
    if (start == end)
    {
        for (int i = 0; i <= end; i++)
            cout << a[i] << " ";
        cout << "\n";
    }

    else
    {
        for (int i = start; i <= end; i++)
        {
            swap(a[start], a[i]);
            Permutations(a, start + 1, end);
            swap(a[start], a[i]);
        }
    }
}

void swap(char a, char b)
{
    char temp = a;
    a = b;
    b = temp;
}
