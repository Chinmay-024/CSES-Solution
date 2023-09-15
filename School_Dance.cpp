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
const ll N = 1e3 + 7;
const ll MOD = 1e9 + 7;

vvi cap(N, vi(N, 0));
ll n, m, k;

ll bfs(ll s, ll t, vi adj[], vi &par)
{
    fill(par.begin(), par.end(), -1);
    queue<pair<ll, ll>> q;
    q.push({s, (ll)INT_MAX});
    par[s] = -2;
    ll maxFlow1 = INT_MAX;
    while (!q.empty())
    {
        ll cur = q.front().ff;
        ll flow = q.front().ss;
        q.pop();
        for (auto i : adj[cur])
        {
            if (par[i] == -1 && cap[cur][i])
            {
                par[i] = cur;
                maxFlow1 = min(flow, cap[cur][i]);
                q.push({i, maxFlow1});
                if (i == t)
                {
                    return maxFlow1;
                }
            }
        }
    }
    return 0;
}

void dfs(int s, vi adj[], vi &vis)
{
    vis[s] = 1;
    cout << s << "\n";
    for (auto i : adj[s])
    {
        if (vis[i] == 0 && cap[s][i])
        {
            dfs(i, adj, vis);
        }
    }
}

void maxFlow(ll s, ll t, vi adj[])
{
    vi par(n + m + 2, -1);
    ll Flow = 0;
    ll ansFlow = 0;
    // cout << bfs(s, t, adj, par);
    while (Flow = bfs(s, t, adj, par))
    {
        ll cur = t;
        ansFlow += Flow;
        while (cur != s)
        {
            ll p = par[cur];
            cap[p][cur] -= Flow;
            cap[cur][p] += Flow;
            cur = p;
        }
    }

    cout << ansFlow << "\n";
    vi vis(n + m + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        for (auto j : adj[i])
        {
            if (cap[i][j] == 0 && j != 0)
                cout << i << " " << j - n << "\n";
        }
    }
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    vi adj[n + m + 2];
    rep(i, 0, k)
    {
        ll x, y;
        cin >> x >> y;
        if (find(adj[x].begin(), adj[x].end(), n + y) == adj[x].end())
            adj[x].push_back(n + y);
        if (find(adj[n + y].begin(), adj[n + y].end(), x) == adj[n + y].end())
            adj[n + y].push_back(x);
        cap[x][n + y] = 1;
    }
    rep(i, 0, n)
    {
        adj[0].push_back(i + 1);
        adj[i + 1].push_back(0);
        cap[0][i + 1] = 1;
    }
    rep(i, 0, m)
    {
        adj[i + n + 1].push_back(n + m + 1);
        adj[m + n + 1].push_back(n + i + 1);
        cap[i + n + 1][m + n + 1] = 1;
    }
    maxFlow(0, n + m + 1, adj);
    return 0;
}