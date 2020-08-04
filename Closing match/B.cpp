#include <iostream>
using namespace std;
int main()
{
    long long n;
    while (cin >> n && n)
    {
        long long cnt = 0;
        while (n)
        {
            if (n % 2 == 0)
                cnt++;
            n = n / 2;
        }
        cout << cnt << endl;
    }
    return 0;
}