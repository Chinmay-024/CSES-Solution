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
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

ll st[(ll)2e5 + 5];
ll en[(ll)2e5 + 5];
vi wt((ll)2e5 + 5);
vi wt1((ll)2e5 + 5);
ll n;
static int timer = 1;
void dfs(int x, int p, vi adj[])
{
    st[x] = timer++;
    for (int i : adj[x])
    {
        if (i != p)
        {
            dfs(i, x, adj);
        }
    }
    en[x] = timer - 1;
}

void built()
{
    for (int i = 1; i <= n; i++)
    {
        int p = i + (i & (-i));
        if (p <= n)
            wt1[p] += wt1[i];
    }
}

ll query(int x)
{
    ll ans = 0;
    while (x > 0)
    {
        ans += wt1[x];
        x -= (x & (-x));
    }
    return ans;
}

void update(ll x, ll y, ll z)
{
    while (x <= n)
    {
        wt1[x] += y;
        x += (x & (-x));
    }
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q;
    cin >> n >> q;
    vi v(n + 1);
    rep(i, 1, 1 + n)
    {
        cin >> v[i];
    }
    vi adj[n + 1];
    rep(i, 0, n - 1)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, -1, adj);
    rep(i, 1, 1 + n)
    {
        wt[st[i]] = v[i];
        wt1[st[i]] = wt[st[i]];
    }
    built();
    rep(i, 0, q)
    {
        int q, s;
        cin >> q >> s;
        if (q == 1)
        {
            int x;
            cin >> x;
            update(st[s], x - wt[st[s]], 1);
            wt[st[s]] = x;
        }
        else
        {
            cout << query(en[s]) - query(st[s] - 1) << "\n";
        }
    }

    return 0;
}