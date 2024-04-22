#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
void Permutations(char *a, const int m);
int main()
{
    char array[4] = {'a', 'b', 'c', 'd'};
    Permutations(array, 3);

    return 0;
}

void Permutations(char *a, const int m)
{
    do
    {
        copy(a, a + m + 1, ostream_iterator<char>(cout, ""));
        cout << endl;
    } while (next_permutation(a, a + m + 1));
}