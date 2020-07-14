#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int MAX = 0x3f3f3f;
int father[MAX];
int sum[MAX];

//找根结点
int find(int x)
{
    if (father[x] != x) //路径压缩
        father[x] = find(father[x]);
    return father[x];
}
//连接
void join(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        father[fx] = fy;
        sum[fy] += sum[fx];
    }
}

int main()
{
    int n, x, y, maxPoint, ans;
    while (~scanf("%d",&n))
    {
        //初始化
        maxPoint = 0;
        ans = 1;
        for (int i = 0; i < 1000000; i++)
        {
            father[i] = i;
            sum[i] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d %d",&x,&y);
            join(x, y);
            maxPoint = max(maxPoint, max(x, y));
        }
        for (int i = 1; i <= maxPoint; i++)
            ans = max(ans, sum[i]);
        cout << ans << endl;
    }
    return 0;
}
