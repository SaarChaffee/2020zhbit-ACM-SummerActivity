#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int G[105][105];
int d[105];
vector<int> e[105];

void topsort(int n)
{
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (!d[i])
        {
            q.push(i);
        }
    }
    int count = 0;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        count++;
        for (int i = 0; i < e[p].size(); i++)
        {
            int y = e[p][i];
            d[y]--;
            if (!d[y])
            {
                q.push(y);
            }
        }
    }
    if (count == n)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    int m, n;
    while (cin >> n >> m)
    {
        if (!n && !m)
            break;
        int u, v;
        for (int i = 0; i < n; i++)
        {
            e[i].clear();
        }
        memset(G, 0, sizeof(G));
        memset(d, 0, sizeof(d));
        while (m--)
        {
            cin >> u >> v;
            e[u].push_back(v);
            d[v]++;
        }
        topsort(n);
    }
    return 0;
}
