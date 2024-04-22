#include "Stack.cpp"
#include "Stack.h"

using namespace std;

struct offsets
{
    int a, b;
};
enum directions
{
    N,
    NE,
    E,
    SE,
    S,
    SW,
    W,
    NW
};

// 1: 통로가 막혀있음. 0: 통과할 수 있음
int maze[13][17] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1}, {1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1}, {1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1}, {1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1}, {1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1}, {1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int mark[13][17] = {
    0,
};
offsets moves[8] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

struct items
{
    int x, y, dir;
};
template <class U> ostream &operator<<(ostream &os, items &item)
{
    return os << item.x << "," << item.y << "," << item.dir;
}

template <class U> ostream &operator<<(ostream &os, Stack<T> &s)
{
    os << "top = " << s.top << endl;
    for (int i = 0; i <= s.top; i++)
        os << i << ":" << s.stack[i] << endl;
    return os;
}

void Path(const int m, const int p)
{
    mark[1][1] = 1;
    Stack<items> stack(m * p);
    items temp;
    temp.x = 1;
    temp.y = 1;
    temp.dir = E;
    stack.Push(temp);

    while (!stack.IsEmpty())
    {
        temp = stack.Top();
        stack.Pop();
        int i = temp.x;
        int j = temp.y;
        int d = temp.dir;

        while (d < 8)
        {
            int g = i + moves[d].a;
            int h = j + moves[d].b;
            if ((g == m) && (h == p))
            {
                cout << stack;
                cout << i << " " << j << endl;
                cout << m << " " << p << endl;
                return;
            }

            if ((maze[g][h] == 0) && (!mark[g][h]))
            {
                mark[g][h] = 1;
                temp.x = i;
                temp.y = j;
                temp.dir = d + 1;
                stack.Push(temp);
                i = g;
                j = h;
                d = N;
            }
            else
            {
                d++;
            }
        }
    }
    cout << "No path in maze" << endl;
}

int main()
{

    return 0;
}
