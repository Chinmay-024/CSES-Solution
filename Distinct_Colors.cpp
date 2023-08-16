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

struct FT
{
    vector<ll> ftree;
    ll n;
    FT(ll q)
    {
        n = q + 1;
        ftree = vi(n + 1, 0);
    }
    ll query(ll i)
    {
        i++;
        ll ans = 0;
        while (i > 0)
        {
            ans += ftree[i];
            i -= (i & (-i));
        }
        return ans;
    }
    void update(ll i, ll x)
    {
        i++;
        while (i < 1 + n)
        {
            ftree[i] += x;
            i += (i & (-i));
        }
    }
};

vector<ll> lend(N, 0);
vector<ll> tour(N, 0);
vector<ll> color(N, 0);
ll idx = 0;

void dfs(ll x, ll p, vi adj[])
{
    lend[x] = idx;
    for (auto i : adj[x])
    {
        if (i != p)
            dfs(i, x, adj);
    }
    tour[idx] = x;
    idx++;
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    FT ft(n);
    rep(i, 1, 1 + n)
    {
        cin >> color[i];
    }

    vi adj[n + 2];
    rep(i, 0, n - 1)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1, adj);
    unordered_map<ll, ll> last;
    vi ans(n + 1, 0);
    rep(i, 0, n)
    {
        ll x = tour[i];
        if (last.count(color[x]))
        {
            ft.update(last[color[x]], -1);
        }
        last[color[x]] = i;
        ft.update(i, 1);
        ans[x] = ft.query(i) - ft.query(lend[x] - 1);
    }
    rep(i, 1, 1 + n)
            cout
        << ans[i] << " ";
}
//   1
// 2   3
//    4  5