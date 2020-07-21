#define mid ((l + r) >> 1)
#define lson node << 1, l, mid
#define rson node << 1 | 1, mid + 1, r

int a[500500];      //原数组
int b[500500 << 2]; //自己建的线段树数组，一般为原数组大小4被

//建树
void build(int node, int l, int r)
{
    if (l == r)
    {
        b[node] = a[l];
    }
    else
    {
        int mid = (l + r) >> 1;
        build(node << 1, l, mid);
        build(node << 1 | 1, mid + 1, r);
        b[node] = b[node << 1] + b[node << 1 | 1];
    }
}

//单点更新（区间最大值）
void update(int node, int l, int r, int pos, int num)
{
    if (l == r && l == pos)
    {
        maxx[node] = num;
    }
    else
    {
        if (pos <= mid)
        {
            update(lson, pos, num);
        }
        else
        {
            update(rson, pos, num);
        }
        maxx[node] = max(maxx[node << 1], maxx[node << 1 | 1]);
    }
}

//区间查询
int query(int node, int l, int r, int L, int R)
{
    if (r < L || l > R)
    {
        return 0;
    }
    if (L <= l && r <= R)
    {
        return b[node];
    }
    int mid = (l + r) >> 1;
    return query(node << 1, l, mid, L, R) + query(node << 1 | 1, mid + 1, r, L, R);
}

int query(int node, int l, int r, int L, int R)
{
    if (L <= l && r <= R)
    {
        return b[node];
    }
    else
    {
        {
            int sum = 0;
            int mid = (l + r) >> 1;
            if (L <= mid)
            {
                sum += query(node << 1, l, mid, L, R);
            }
            if (R > mid)
            {
                sum += query(node << 1 | 1, mid + 1, r, L, R);
            }
            return sum;
        }
    }
}

//////////////////////////////////////////////////////////
//lazy数组
void pushdown(int node, int l, int r)
{
    if (lazy[node])
    {
        lazy[node << 1] += lazy[node];
        lazy[node << 1 | 1] += lazu[node];
        int mid = (l + r) >> 1;
        a[node << 1] += lazy[node] * (mid - l + 1);
        a[node << 1 | 1] += lazy[node] * (r - mid);
        lazy[node] = 0;
    }
}

//区间更新
void update(int node, int l, int r, int L, int R, int P)
{
    if (r < L || l > R)
    {
        return;
    }
    if (L <= l && r <= R)
    {
        a[node] += P * (r - l + 1);
        lazy[node] += P;
    }
    else
    {
        pushdown(node, l, r);
        int mid = (l + r) >> 1;
        update(node << 1, l, mid, L, R, P);
        update(node << 1 | 1, mid + 1, r, L, R, P);
        a[node] = a[node << 1] + a[node << 1 | 1];
    }
}

//区间查询
long long query(int node, int l, int r, int L, int R)
{
    if (r < L || l > R)
    {
        return 0;
    }
    if (L <= l && r <= R)
    {
        return a[node];
    }
    pushdown(node, l, r);
    int mid = (l + r) >> 1;
    return query(node << 1, l, mid, L, R) + query(node << 1 | 1, mid + 1, r, L, R);
}