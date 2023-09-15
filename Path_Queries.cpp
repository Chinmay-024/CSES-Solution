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

vi wt(N, 0);
vi wt1(N, 0);
ll st[(ll)2e5 + 5];
ll en[(ll)2e5 + 5];

vector<ll> a(N, 0);
vector<ll> Tree(4 * N, 0);
vector<ll> Lazy(4 * N, 0);

ll n, q;
ll timer = 0;
void dfs(ll x, ll p, vi adj[], ll wt1)
{
    ll ans = 0;
    st[x] = timer++;
    wt[x] += wt1;
    for (auto i : adj[x])
    {
        if (i != p)
        {
            dfs(i, x, adj, wt[x]);
        }
    }

    en[x] = timer - 1;
}

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
    if (st > high || en < low || low > high)
        return;
    if (st == low && en == high)
    {
        Lazy[node] += val;
        Tree[node] += val;
    }
    else
    {
        push(node);
        ll mid = (st + en) / 2;
        update(2 * node, st, mid, low, min(high, mid), val);
        update(2 * node + 1, mid + 1, en, max(mid + 1, low), high, val);
        Tree[node] = Tree[2 * node + 1] + Tree[2 * node];
    }
    // cout << node << " ? " << Tree[node] << "\n";
}

ll query(ll node, ll st, ll en, ll idx)
{
    if (st > idx || en < idx || st > en)
        return 0;
    if (st == en && st == idx)
        return Tree[node];
    push(node);
    ll mid = (st + en) / 2;
    ll a = 0, b = 0;
    a = query(2 * node, st, mid, idx);
    b = query(2 * node + 1, mid + 1, en, idx);
    return a + b;
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    rep(i, 1, n + 1)
    {
        cin >>
            wt[i];
        wt1[i] = wt[i];
    }
    vi adj[n + 1];
    rep(i, 0, n - 1)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, -1, adj, 0);

    for (ll i = 1; i < n + 1; i++)
        a[st[i]] = wt[i];
    // rep(i, 0, n)
    //         cout
    //     << a[i] << " - ";
    build(1, 0, n - 1);
    rep(i, 0, q)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll s, x;
            cin >> s >> x;
            ll diff = x - wt1[s];
            update(1, 0, n - 1, st[s], en[s], diff);
            wt1[s] = x;
            // cout << "UPDATE -> ";
            // for (ll i = 1; i <= n; i++)
            // {
            //     cout << query(1, 0, n - 1, st[i]) << " ";
            // }
            // cout << "\n";
        }
        else
        {
            ll s;
            cin >> s;
            cout << query(1, 0, n - 1, st[s]) << "\n";
        }
    }
    return 0;
}