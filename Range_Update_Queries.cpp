#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i, j, n) for (ll i = j; i < n; i++)
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair<ll, ll>
#define vii vector<pii>
#define ff first
#define ss second

const ll M = 2e6 + 20;
vector<ll> fact(M, 1);
const ll N = 2e5 + 7;
const ll MOD = 1e9 + 7;

vector<ll> a(N, 0);
vector<ll> Tree(4 * N, 0);
vector<ll> Lazy(4 * N, 0);

void build(ll node, ll st, ll en)
{
    if (st == en)
    {
        Tree[node] = a[st];
        return;
    }
    ll mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);
    Tree[node] = Tree[2 * node + 1] + Tree[2 * node];
}

void push(ll node)
{
    Tree[2 * node] += Lazy[node];
    Tree[2 * node + 1] += Lazy[node];
    Lazy[node * 2] += Lazy[node];
    Lazy[2 * node + 1] += Lazy[node];
    Lazy[node] = 0;
}

void update(ll node, ll st, ll en, ll low, ll high, ll val)
{
    if (st > high || en < low)
        return;
    if (st >= low && en <= high)
    {
        Lazy[node] += val;
        Tree[node] += val;
    }
    else
    {
        push(node);
        ll mid = (st + en) / 2;
        update(2 * node, st, mid, low, high, val);
        update(2 * node + 1, mid + 1, en, low, high, val);
        Tree[node] = Tree[2 * node + 1] + Tree[2 * node];
    }
}

ll query(ll node, ll st, ll en, ll idx)
{
    if (st > idx || en < idx)
        return 0;
    if (st == en && st == idx)
        return Tree[node];
    else
    {
        push(node);
        ll mid = (st + en) / 2;
        ll a = 0, b = 0;
        if (idx <= mid)
            a = query(2 * node, st, mid, idx);
        else
            b = query(2 * node + 1, mid + 1, en, idx);
        return a + b;
    }
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    rep(i, 0, q)
    {
        ll x;
        cin >> x;
        if (x == 1)
        {
            ll a, b, u;
            cin >> a >> b >> u;
            update(1, 0, n - 1, a - 1, b - 1, u);
        }
        else
        {
            ll idx;
            cin >> idx;
            cout << query(1, 0, n - 1, idx - 1) << "\n";
        }
    }
    return 0;
}