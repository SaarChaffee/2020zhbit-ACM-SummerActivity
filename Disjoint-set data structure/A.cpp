#include <iostream>
using namespace std;

const int MAX = 0x3f3f3f;
int father[MAX];

int fi(int k)
{
    if (father[k] != k)
        father[k] = fi(father[k]);
    return father[k];
}

void join(int a, int b)
{
    int x = fi(a);
    int y = fi(b);
    if (x != y)
        father[x] = y;
}

int main()
{
    int n, m;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        cin >> m;
        for (int i = 1; i <= n; i++)
            father[i] = i;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            join(a, b);
        }
        int s = 0;
        for (int i = 1; i <= n; i++)
        {
            if (father[i] == i)
                s++;
        }
        cout << s - 1 << endl;
    }
    return 0;
}
