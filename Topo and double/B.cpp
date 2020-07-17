#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int f[550], map[505][505], ans[505];

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        int a, b;
        memset(f, 0, sizeof(f)); //初始化
        memset(map, 0, sizeof(map));
        for (int i = 1; i <= n; i++)
            map[i][i] = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            if (!map[a][b])
            {
                map[a][b] = 1; //标记a赢了b
                f[b]++;        //b的度数+1
            }
        }
        int k = 0;
        for (int i = 1; i <= n; i++) //拓扑排序
        {
            for (int j = 1; j <= n; j++)
            {
                if (!f[j]) //度数为0
                {
                    a = j;
                    break;
                }
            }
            ans[k++] = a; //记录名词
            f[a]--;       //踢出范围
            for (int j = 1; j <= n; j++)
            {
                if (map[a][j]) //和k比赛且输的人的度数-1
                {
                    f[j]--;
                }
            }
        }
        for (int i = 0; i < k - 1; i++) //格式化输出
            cout << ans[i] << " ";
        cout << ans[k - 1] << endl;
    }
}