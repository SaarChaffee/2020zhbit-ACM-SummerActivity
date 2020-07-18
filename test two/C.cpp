#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    long long int t, ans, k;
    scanf("%lld", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%lld %lld", &ans, &k);
        for (int j = 1; j < k; j++)
        {
            int min = 10, max = 0, b = 0;
            long long int s = ans;
            while (s)
            {
                b = s % 10;
                if (b >= max)
                {
                    max = b;
                }
                if (b <= min)
                {
                    min = b;
                }
                if (min == 0)
                {
                    break;
                }
                s /= 10;
            }
            if (min == 0)
            {
                break;
            }
            ans += max * min;
        }
        printf("%lld\n", ans);
    }
    return 0;
}