#include <iostream>
#include <cstring>
using namespace std;
int n, m, vis[30][30], ans;
int dir[4][2] =
    {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char nmap[30][30];
void dfs(int x, int y)
{
    ans++;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && nmap[nx][ny] == '.')
            dfs(nx, ny);
    }
}

int main()
{
    while (cin >> m >> n, m != 0, n != 0)
    {
        ans = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++)
            cin >> nmap[i];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (nmap[i][j] == '@' && !vis[i][j])
                {
                    dfs(i, j);
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
