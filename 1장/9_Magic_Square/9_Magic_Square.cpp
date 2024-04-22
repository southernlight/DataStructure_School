#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void Magic(const int n);
int main()
{
    Magic(5);

    return 0;
}

void Magic(const int n)
{
    int magicSquare[n][n];
    int k, l;

    // 배열에 0넣기
    memset(magicSquare, 0, sizeof(magicSquare));
    // 첫번째 자리(첫번 째 행 중앙에 1넣기 위해서 자리 설정)
    int i = 0;
    int j = n / 2;
    magicSquare[i][j] = 1;

    int num = 2;
    while (num <= n * n)
    {
        if (i - 1 < 0)
            k = n - 1;
        else
            k = i - 1;
        if (j - 1 < 0)
            l = n - 1;
        else
            l = j - 1;

        if (magicSquare[k][l])
        {
            i = (i + 1) % n;
        }
        else
        {
            i = k;
            j = l;
        }

        magicSquare[i][j] = num;
        num++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << magicSquare[i][j] << " ";
        }
        cout << endl;
    }
}