#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int maps[155][155];
int dis[155], vis[155];
int n, m, t;
int nmax = 0;
void dijkstra()
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = maps[1][i];
    }
    dis[1] = 0;
    vis[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int tmp = -1;
        for (int j = 1; j <= n; j++)
        {
            if ((tmp == -1 || dis[tmp] > dis[j]) && vis[j] == 0)
            {
                tmp = j;
            }
        }
        vis[tmp] = 1;
        for (int j = 1; j <= n; j++)
        {
            if (vis[j] == 0 && (dis[tmp] + maps[tmp][j] < dis[j]))
            {
                dis[j] = dis[tmp] + maps[tmp][j];
            }
        }
    }
    return;
}

int main()
{
    char s[5];
    char t[5] = "x";
    while (cin >> n && 1 <= n && n <= 100)
    {
        nmax = 0;
        memset(maps, INF, sizeof(maps));
        memset(dis, INF, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++)
            maps[i][i] = 0;
        int x, y, z;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i - 1; j++)
            {
                cin >> s;
                if (!strcmp(s, t))
                {
                    maps[i][j] = INF;
                }
                else
                {
                    maps[i][j] = atoi(s);
                    maps[j][i] = atoi(s);
                }
            }
        }
        dijkstra();
        int sum = -INF;
        for (int i = 2; i <= n; ++i)
        {
            if (dis[i] > sum)
            {
                sum = dis[i];
            }
        }
        cout << sum << endl;
    }
    return 0;
}
