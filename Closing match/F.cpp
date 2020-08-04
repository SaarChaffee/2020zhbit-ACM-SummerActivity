#include <iostream>
#include <cstring>

using namespace std;

long long dp[10000010];

int main()
{
    int n, m, o;
    int i, j, k;
    memset(dp, 0, sizeof(dp));
    dp[1] = 1;
    dp[2] = 2;
    for (i = 3; i <= 10000001; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    while (~scanf("%d", &o) && o >= 0 && o <= 10000000)
        cout << dp[o] << endl;
    return 0;
}
