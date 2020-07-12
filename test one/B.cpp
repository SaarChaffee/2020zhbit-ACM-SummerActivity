#include <iostream>
#include <cstring>
using namespace std;
int a[2020], vis[2020], tt[2020];

int main()
{
    int t, num, n, k;
    cin >> t;
    while (t--)
    {
        memset(vis, 0, sizeof(vis));
        cin >> n >> k;
        num = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (vis[a[i]] == 0)                  //找不相同的数，个数为num
                vis[a[i]] = 1, tt[++num] = a[i]; //tt存储这些不同的数
        }
        if (num > k)
            cout << -1;
        else
        {
            for (int i = num + 1; i <= k; i++)
                tt[i] = tt[i - 1]; //创造一个周期的数组
            for (int i = k + 1; i <= 666; i++)
                tt[i] = tt[i - k]; //构造
            cout << 666 << endl;
            for (int i = 1; i <= 666; i++)
                cout << tt[i] << " ";
        }
        cout << endl;
    }
}