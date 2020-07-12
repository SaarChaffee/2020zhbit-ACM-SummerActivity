#include <iostream>
using namespace std;

int main()
{
    int m;
    cin >> m;
    while (m-- && m <= 100)
    {
        int n;
        cin >> n;
        if (!(2 <= n && n <= 30))
            break;
        long long x = 0;
        for (int i = 2; i <= n; i += 2)
        {
            x = x * 2 + 2;
        }
        cout << x << endl;
    }
    return 0;
}
