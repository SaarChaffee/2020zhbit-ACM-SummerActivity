#include <iostream>
#include <cstring>
using namespace std;
int n, m, vis[110][110], sum;
int dir[8][2] =
    {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
char nmap[110][110];

void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >= 0 && ny >= 0 && nx < m && ny < n && !vis[nx][ny] && nmap[nx][ny] == '@')
        {
            dfs(nx, ny);
        }
    }
}
int main()
{
    while (cin >> m >> n && m > 0 && n > 0 && m <= 100 && n <= 100)
    {
        sum = 0;
        memset(vis, 0, sizeof(vis));
        memset(nmap, 0, sizeof(nmap));
        for (int i = 0; i < m; i++)
        {
            cin >> nmap[i];
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nmap[i][j] == '@' && !vis[i][j])
                {
                    dfs(i, j);
                    sum++;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
