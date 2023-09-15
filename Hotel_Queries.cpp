#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i, j, n) for (int i = j; i < n; i++)
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second

const ll M = 2e6 + 20;
vector<ll> fact(M, 1);
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;
ll n;

vi a(N);
vi Tree(4 * N);

void build(int node, int st, int en)
{
    if (st == en)
    {
        Tree[node] = a[st];
        return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);
    Tree[node] = max(Tree[node * 2], Tree[node * 2 + 1]);
}

void update(int node, int idx, int st, int en, int val)
{
    if (st == en)
    {
        Tree[node] -= val;
        a[st] -= val;
        return;
    }
    int mid = (st + en) / 2;
    if (idx <= mid)
        update(2 * node, idx, st, mid, val);
    else
        update(2 * node + 1, idx, mid + 1, en, val);
    Tree[node] = max(Tree[node * 2], Tree[node * 2 + 1]);
}

int query(int node, int st, int en, int val)
{
    if (st > en)
        return -1;

    if (st == en)
    {
        if (a[st] >= val)
            return st;
        else
            return -1;
    }
    int mid = (st + en) / 2;

    if (Tree[2 * node] >= val)
        return query(2 * node, st, mid, val);
    else
        return query(2 * node + 1, mid + 1, en, val);
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ll m;
    cin >> m;
    rep(i, 0, n) cin >> a[i];
    build(1, 0, n - 1);
    rep(i, 0, m)
    {
        int x;
        cin >> x;
        int q = query(1, 0, n - 1, x);
        if (q == -1)
            cout << "0 ";
        else
        {
            cout << q + 1 << " ";
            update(1, q, 0, n - 1, x);
        }
    }
    return 0;
}