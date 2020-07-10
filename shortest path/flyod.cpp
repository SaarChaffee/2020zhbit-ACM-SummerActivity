#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define INF 0x3f3f3f3f
using namespace std;
int maps[30][30];
int n, m, t;
void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                maps[i][j] = min(maps[i][j], maps[i][k] + maps[k][j]);
}
int main()
{
    while (cin >> n >> m >> t)
    {
        memset(maps, INF, sizeof(maps));
        for (int i = 1; i <= n; i++)
            maps[i][i] = 0;
        int x, y, z;
        while (m--)
        {
            cin >> x >> y >> z;
            maps[x][y] = min(maps[x][y], z);
        }
        floyd();
        while (t--)
        {
            cin >> x >> y;
            cout << maps[x][y] << endl;
        }
    }
    return 0;
}