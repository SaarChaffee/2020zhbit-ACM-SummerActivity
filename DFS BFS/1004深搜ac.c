#include <iostream>
using namespace std;
int m, n;
char nmap[120][120];
int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {0, -1}, {1, 1}, {1, 0}, {1, -1}};

void dfs(int x, int y)
{
    int i;
    nmap[x][y] = '*';
    for (i = 0; i < 8; i++)
    {
        int sex = x + dir[i][0];
        int sey = y + dir[i][1];
        if (sex < 0 || sex >= m || sey < 0 || sey >= n)
        {
            continue;
        }
        if (nmap[sex][sey] == '@')
            dfs(sex, sey);
    }
}

int main()
{
    int i, j;
    while (cin >> m >> n)
    {
        int sum = 0;
        if (m == 0 && n == 0)
        {
            break;
        }
        for (i = 0; i < m; i++)
        {
            cin >> nmap[i];
        }
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (nmap[i][j] == '@')
                {
                    sum++;
                    dfs(i, j);
                }
            }
        }
        cout << sum << endl;
    }

    return 0;
}
