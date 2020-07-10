#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int nmap[25][25];

void floyd(int n)
{
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (nmap[i][k] + nmap[k][j] < nmap[i][j])
                    nmap[i][j] = nmap[i][k] + nmap[k][j];
}

int main()
{

    int n, x, i, s, t, count = 0;
    while (~scanf("%d", &n))
    {
        memset(nmap, 0x3f, sizeof(nmap));
        while (n--)
        {
            cin >> x;
            nmap[1][x] = nmap[x][1] = 1;
        }
        for (i = 2; i <= 19; i++)
        {
            cin >> n;
            while (n--)
            {
                cin >> x;
                nmap[i][x] = nmap[x][i] = 1;
            }
        }
        floyd(20);
        cin >> n;
        printf("Test Set #%d\n", ++count);
        while (n--)
        {
            cin >> s >> t;
            printf("%d to %d: %d\n", s, t, nmap[s][t]);
        }
        cout << endl;
    }
    return 0;
}