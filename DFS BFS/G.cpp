#include <bits/stdc++.h>
using namespace std;
int n, m, vis[210][210], sum, ok;
int dir[4][2] =
    {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char nmap[210][210];

void dfs(int x, int y, int step)
{
    if (vis[x][y] || nmap[x][y] == '#' || step >= sum)
        return;
    if (nmap[x][y] == 'r')
    {
        ok = 1;
        if (step < sum)
            sum = step;
        return;
    }
    if (nmap[x][y] == 'x')
        step++;
    vis[x][y] = 1;
    dfs(x + 1, y, step + 1);
    dfs(x - 1, y, step + 1);
    dfs(x, y + 1, step + 1);
    dfs(x, y - 1, step + 1);
    vis[x][y] = 0;
}

int main()
{
    int dx, dy;
    while (cin >> m >> n && m > 0 && n > 0 && m <= 200 && n <= 200)
    {
        ok = 0;
        sum = 0x3f3f3f;
        memset(vis, 0, sizeof(vis));
        memset(nmap, '#', sizeof(nmap));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> nmap[i][j];
                if (nmap[i][j] == 'a')
                {
                    dx = i;
                    dy = j;
                }
            }
        }
        dfs(dx, dy, 0);
        if (ok)
            cout << sum << endl;
        else
            cout << "Poor ANGEL has to stay in the prison all his life." << endl;
    }
    return 0;
}
