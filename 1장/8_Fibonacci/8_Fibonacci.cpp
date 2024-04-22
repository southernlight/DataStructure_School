#include <iostream>

using namespace std;

int main()
{

    return 0;
}

void Fibonacci(int n)
{
    if (n <= 1)
        cout << n << endl;
    else
    {
        int fn;
        int fnm1 = 1;
        int fnm2 = 0;

        for (int i = 2; i <= n; i++)
        {
            fn = fnm1 + fnm2;
            fnm2 = fnm1;
            fnm1 = fn;
        }
        cout << fn << endl;
    }
}