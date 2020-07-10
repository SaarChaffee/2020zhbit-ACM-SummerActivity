#include <iostream>
#include <cstring>
using namespace std;
int n, m, vis[30][30], sum;
int dir[4][2] =
    {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char nmap[30][30];

void dfs(int x, int y)
{
    sum++;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >=0 && ny >=0 && nx<m && ny <n && !vis[nx][ny] && nmap[nx][ny] == '.')
            dfs(nx, ny);
    }
}
int main()
{
    while (cin >> n >> m && m>0 && n>0 && m<=20 && n<=20)
    {
        sum = 0;
        memset(vis, 0, sizeof(vis));
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
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
