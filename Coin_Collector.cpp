#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i, j, n) for (ll i = j; i < n; i++)
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

stack<ll> topo;

void dfs(ll x, vi adj[], vi &visited)
{
    if (visited[x])
        return;
    visited[x] = 1;
    for (auto i : adj[x])
    {
        if (!visited[i])
        {
            dfs(i, adj, visited);
        }
    }
    topo.push(x);
}

void rdfs(ll x, vi radj[], vi &parent, ll i)
{
    parent[x] = i;
    for (auto j : radj[x])
        if (parent[j] == -1)
            rdfs(j, radj, parent, i);
}

vector<ll> dp;

ll DP(ll x, vi fadj[], vi wt)
{
    if (dp[x] != -1)
        return dp[x];
    ll ans = 0;
    for (auto i : fadj[x])
        ans = max(ans, DP(i, fadj, wt));
    dp[x] = ans + wt[x];
    return dp[x];
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vi k(n);
    ll count = 0;
    rep(i, 0, n)
    {
        cin >> k[i];
    }
    vi adj[n];
    vi radj[n];
    rep(i, 0, m)
    {
        ll x, y;
        cin >> x >> y;
        adj[--x].push_back(--y);
        radj[y].push_back(x);
    }
    vi visited(n, 0);
    rep(i, 0, n)
    {
        if (!visited[i])
            dfs(i, adj, visited);
    }
    vi parent(n, -1);
    visited = vi(n, 0);
    while (!topo.empty())
    {
        ll x = topo.top();
        topo.pop();
        if (parent[x] == -1)
        {
            rdfs(x, radj, parent, count);
            count++;
        }
    }

    vi fadj[count + 1];
    rep(i, 0, n)
    {
        for (auto k : adj[i])
        {
            if (parent[i] != parent[k])
                fadj[parent[i]].push_back(parent[k]);
        }
    }
    vi wt(count + 1, 0);
    dp = vector<ll>(count + 5, -1);
    rep(i, 0, n)
    {
        wt[parent[i]] += k[i];
    }
    // rep(i, 0, count)
    // {
    //     cout << i << " " << wt[i] << " - ";
    //     for (auto k : fadj[i])
    //         cout << k << ",";
    //     cout << "\n";
    // }
    ll ans = 0;
    rep(i, 0, count)
    {
        ans = max(ans, DP(i, fadj, wt));
    }
    cout << ans;
    return 0;
}