#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define INF 0x3f3f3f3f
using namespace std;

int maps[2020][2020];
int dis[2020], vis[2020];
int n, m;

void dijkstra()
{
    for (int i = 1; i <= m; i++)
    {
        dis[i] = maps[1][i];
    }
    dis[1] = 0;
    vis[1] = 1;
    for (int i = 2; i <= m; i++)
    {
        int tmp = -1;
        for (int j = 1; j <= m; j++)
        {
            if ((tmp == -1 || dis[tmp] > dis[j]) && vis[j] == 0)
            {
                tmp = j;
            }
        }
        vis[tmp] = 1;
        for (int j = 1; j <= m; j++)
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
    while (cin >> n >> m && 0 < n && n <= 2000 && 1 < m && m <= 1000)
    {
        memset(maps, INF, sizeof(maps));
        memset(dis, INF, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++)
            maps[i][i] = 0;
        int x, y, z;
        while (n--)
        {
            cin >> x >> y >> z;
            maps[x][y] = min(maps[x][y], z);
            maps[y][x] = min(maps[y][x], z);
        }
        // for (int i = 1; i <= m; i++)
        // {
        //     for (int j = 1; j <= m; j++)
        //         cout << maps[i][j] << "                     ";
        //     cout << endl;
        // }
        dijkstra();
        cout << dis[m] << endl;
    }
    return 0;
}