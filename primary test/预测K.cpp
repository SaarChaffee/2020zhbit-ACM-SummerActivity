#include <iostream>
using namespace std;
#define inf 0x3f3f3f3f
int nmap[105][105], dis[105], vis[105];
int n, m;
void dijkstra(int position)
{
    int i, j, k;
    for (i = 1; i <= n; i++)
    {
        dis[i] = nmap[position][i];
    }
    for (i = 1; i <= n; i++)
        vis[i] = 0;
    vis[position] = 1;
    for (i = 1; i <= n - 1; i++)
    {
        int mix = inf;
        int u;
        for (j = 1; j <= n; j++)
        {
            if (vis[j] == 0 && mix > dis[j])
            {
                mix = dis[j];
                u = j;
            }
        }
        vis[u] = 1;
        for (k = 1; k <= n; k++)
        {
            if (vis[k] == 0 && dis[k] > dis[u] + nmap[u][k])
                dis[k] = dis[u] + nmap[u][k];
        }
    }
}
int main()
{
    int i, j, k;
    while (cin >> n >> m && n || m)
    {
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
            {
                if (i == j)
                    nmap[i][j] = 0;
                else
                    nmap[i][j] = inf;
            }
        while (m--)
        {
            int x, y, z;
            cin >> x >> y >> z;
            if (nmap[x][y] > z)
            {
                nmap[x][y] = nmap[y][x] = z;
            }
        }
        dijkstra(1);
        cout << dis[n] << endl;
    }
    return 0;
}