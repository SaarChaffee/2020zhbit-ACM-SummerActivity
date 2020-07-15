#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
#define N 1110

int d;
bool use[N];

struct node
{
    int pre;
    int x, y;
} Node[N];

int find(int x)
{
    if (x == Node[x].pre)
        return x;
    else
        return find(Node[x].pre);
}

void join(const node p1, const node p2)
{
    int x1, x2;
    x1 = find(p1.pre);
    x2 = find(p2.pre);
    if (x1 != x2)
        if ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) <= d * d)
            Node[x2].pre = x1;
}

int main()
{
    int num;
    char ope;
    int ok;
    int from, to;
    scanf("%d%d", &num, &d);
    for (int i = 1; i <= num; ++i)
        Node[i].pre = i;
    memset(use, false, sizeof(use));
    for (int i = 1; i <= num; ++i)
        scanf("%d%d", &Node[i].x, &Node[i].y);
    while (scanf("\n%c", &ope) != EOF)
    {
        if (ope == 'O')
        {
            scanf("%d", &ok);
            use[ok] = true;
            for (int i = 1; i <= num; ++i)
                if (use[i] && i != ok)
                    join(Node[i], Node[ok]);
        }
        else
        {
            scanf("%d%d", &from, &to);
            if (find(from) == find(to))
                cout << "SUCCESS" << endl;
            else
                cout << "FAIL" << endl;
        }
    }
    return 0;
}