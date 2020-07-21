#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
#define lson root << 1, l, mid
#define rson root << 1 | 1, mid + 1, r
#define mid ((l + r) >> 1)

const int MAX = 200000 + 5;
int tree[MAX << 2];

void buildTree(int root, int l, int r)
{
    if (l == r)
    {
        scanf("%d", &tree[root]);
        return;
    }
    buildTree(lson);
    buildTree(rson);
    tree[root] = max(tree[root << 1], tree[root << 1 | 1]);
}

void Updata(int root, int l, int r, int p, int v)
{
    if (l == r)
    {
        tree[root] = v;
        return;
    }
    if (p <= mid)
        Updata(lson, p, v);
    else
        Updata(rson, p, v);
    tree[root] = max(tree[root << 1], tree[root << 1 | 1]);
}

int Query(int root, int l, int r, int L, int R)
{
    if (L <= l && r <= R)
        return tree[root];
    int ret = 0;
    if (L <= mid)
        ret = max(ret, Query(lson, L, R));
    if (R > mid)
        ret = max(ret, Query(rson, L, R));
    return ret;
}

int main()
{
    char ch[3];
    int n, m, a, b;
    while (scanf("%d %d", &n, &m) == 2)
    {
        buildTree(1, 1, n);
        for (int i = 1; i <= m; i++)
        {
            scanf("%s %d %d", ch, &a, &b);
            if (ch[0] == 'Q')
                printf("%d\n", Query(1, 1, n, a, b));
            else
                Updata(1, 1, n, a, b);
        }
    }
    return 0;
}