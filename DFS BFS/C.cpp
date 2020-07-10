#include <iostream>
#include <string.h>
using namespace std;

int n, num, sum, m;
char nmap[10][10];
int vis[10];

void dfs(int a)
{
    if (num == m)
    {
        sum++;
        return;
    }
    if (a >= n)
        return;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && nmap[a][i] == '#')
        {
            vis[i] = 1;
            num++;
            dfs(a + 1);
            num--;
            vis[i] = 0;
        }
    }
    dfs(a + 1);
}

int main()
{
    while (cin >> n >> m)
    {
        if (n == -1 && m == -1)
            break;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> nmap[i][j];
        memset(vis, 0, sizeof(vis));
        sum = 0;
        num = 0;
        dfs(0);
        cout << sum << endl;
    }

    return 0;
}