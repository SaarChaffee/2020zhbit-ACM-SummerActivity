#include <queue>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int map[105][105], r[105], topo[105];
int n, m, k;

int topoSort()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        k = -1;
        for (int j = 0; j < n; j++)
        {
            if (r[j] == 0)
            {
                topo[cnt++] = j;
                k = j;
                break;
            }
        }
        if (k == -1)
            break;
        for (int j = 0; j < n; j++) //
        {
            if (map[k][j])
            {
                r[j]--;
            }
        }
        r[k] = -1;
    }
    return cnt;
}

int main()
{
    int x, y;
    while (~scanf("%d%d", &n, &m))
    {
        if (n == 0 || m == 0)
            break;
        memset(r, 0, sizeof r);
        memset(map, 0, sizeof map);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            if (!map[x][y])
            {
                map[x][y] = 1;
                r[y]++;
            }
        }
        int sum = topoSort();
        if (k == -1)
            printf("NO\n");
        else
            printf("YES\n");
    }
}