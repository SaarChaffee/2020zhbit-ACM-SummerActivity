#include <iostream>
using namespace std;

int a[1000005] = {0, 1, 2, 3};

int f(int n)
{
    int x = a[900000], y = a[899999], temp;
    for (int i = 900001; i <= n; i++)
    {
        temp = (x + y) % 1000007;
        y = x;
        x = temp;
    }
    return temp;
}

int main()
{
    int n;
    for (int i = 4; i <= 900000; i++)
        a[i] = (a[i - 1] + a[i - 2]) % 1000007;
    while (~scanf("%d", &n))
    {
        if (n > 900000)
            cout << f(n) << endl;
        else
            cout << a[n] << endl;
    }
    return 0;
}