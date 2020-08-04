#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int n, m, vis[201][201], sum;
int dir[4][2] =
    {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char nmap[201][201];

void dfs(int x, int y)
{
    if (nmap[x][y] == 'O')
    {
        sum++;
        return;
    }
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && nmap[nx][ny] != '#')
        {
            dfs(nx, ny);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t-- && cin >> n >> m && m > 0 && n > 0 && m <= 200 && n <= 200)
    {
        sum = 0;
        memset(vis, 0, sizeof(vis));
        memset(nmap, '#', sizeof(nmap));
        for (int i = 0; i < n; i++)
        {
            cin >> nmap[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (nmap[i][j] == 'S')
                {
                    dfs(i, j);
                    dfs(i, j);
                }
            }
        }
        if (sum == 0)
            cout << "BadEnd" << endl;
        else if (sum == 1)
            cout << "NormalEnd" << endl;
        else if (sum == 2)
            cout << "GoodEnd" << endl;
    } 
	return 0;
}
