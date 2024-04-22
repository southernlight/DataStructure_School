#include <cstring>
#include <iostream>
using namespace std;

void fail(char *pat);
int kmp(char *str, char *pat);
int failure[10];

int main()
{

    return 0;
}

void fail(char *pat)
{
    failure[0] = 0;

    for (int i = 1, j = 0; i < strlen(pat); i++)
    {
        while (j > 0 && pat[i] != pat[j])
            j = failure[j - 1];
        if (pat[i] == pat[j])
        {
            i++;
            j++;
        }
        else
        {
            failure[i] = 0;
        }
    }
}
int kmp(char *str, char *pat)
{
    int i = 0, j = 0;
    int lenS = strlen(str);
    int lenP = strlen(pat);

    while (i < lenS && j < lenP)
    {
        if (str[i] == pat[j])
        {
            i++;
            j++;
        }

        else if (j == 0)
        {
            i++;
        }

        else
        {
            j = failure[j - 1] + 1;
        }
    }

    return (j == lenP ? i - lenP : -1);
}