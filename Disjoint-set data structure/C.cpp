#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 0x3f3f3f;
int father[MAX], sum[MAX];
void init(int n) ///初始化
{
    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
        sum[i] = 1;
    }
}
int find(int x) //查找
{
    if (father[x] != x) //路径压缩
        father[x] = find(father[x]);
    return father[x];
}
void join(int i, int j) //按秩合并
{
    int x = find(i);
    int y = find(j);
    if (sum[x] <= sum[y])
    {
        father[x] = y;
    }
    else
    {
        father[y] = x;
    }
    if (sum[x] == sum[y] && x != y)
    {
        sum[y]++;
    }
}

int main()
{

    int n, m, T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        init(n); ///初始化
        int x, y;
        for (int i = 1; i <= m; i++)
        {
            cin >> x >> y;
            join(x, y); //合并
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (father[i] == i)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
