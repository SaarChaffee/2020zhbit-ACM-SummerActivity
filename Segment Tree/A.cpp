#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct node
{
    int data;
    int l, r;
};

struct node tree[500000];
int Begin[500000];

void buildTree(int root, int l, int r)
{
    tree[root].l = l;
    tree[root].r = r;
    if (l == r)
        tree[root].data = Begin[l];
    else
    {
        int mid = (l + r) / 2;
        buildTree(root * 2 + 1, l, mid);
        buildTree(root * 2 + 2, mid + 1, r);
        tree[root].data = tree[root * 2 + 1].data + tree[root * 2 + 2].data;
    }
}

int Query(int root, int l, int r)
{
    int i = tree[root].l, j = tree[root].r;
    if (i > r || j < l)
        return 0;
    l = max(l, i);
    r = min(r, j);
    if (i == l && j == r)
        return tree[root].data;

    return Query(root * 2 + 1, l, r) + Query(root * 2 + 2, l, r);
}

void Updata(int root, int pos, int data)
{
    int l = tree[root].l, r = tree[root].r;
    if (l > pos || r < pos)
        return;

    tree[root].data += data;

    if (l == r)
        return;

    Updata(root * 2 + 1, pos, data);
    Updata(root * 2 + 2, pos, data);
}

int main()
{
    int t, x = 0;
    scanf("%d", &t);
    while (t--)
    {
        x++;
        memset(tree, 0, sizeof(tree));
        memset(Begin, 0, sizeof(Begin));
        int i, n;
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
            scanf("%d", &Begin[i]);
        buildTree(0, 1, n);

        printf("Case %d:\n", x);

        char order[10];
        while (1)
        {
            scanf("%s", order);
            if (!strcmp(order, "End"))
                break;
            else
            {
                int i, j;
                if (strcmp(order, "Add") == 0)
                {
                    scanf("%d %d", &i, &j);
                    Updata(0, i, j);
                }
                else if (strcmp(order, "Sub") == 0)
                {
                    scanf("%d %d", &i, &j);
                    Updata(0, i, -1 * j);
                }
                else if (strcmp(order, "Query") == 0)
                {
                    scanf("%d %d", &i, &j);
                    printf("%d\n", Query(0, i, j));
                }
            }
        }
    }
    return 0;
}