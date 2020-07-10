#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int chess[12];
int sum;
int n;

bool place(int a)
{
    for (int i = 1; i < a; i++)
        if (abs(i - a) == abs(chess[i] - chess[a]) || chess[i] == chess[a])
            return false;
    return true;
}

void dfs(int a)
{
    if (a > n)
        sum++;
    else
        for (int i = 1; i <= n; i++)
        {
            chess[a] = i;
            if (place(a))
                dfs(a + 1);
        }
}

int main()
{
    int ans[12];
    int x;
    for (int i = 1; i <= 10; i++)
    {
        memset(chess, 0, sizeof(chess));
        sum = 0, n = i;
        dfs(1);
        ans[i] = sum;
    }
    while (cin >> x && x != 0)
    {
        cout << ans[x] << endl;
    }
    return 0;
}