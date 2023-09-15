#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i, j, n) for (int i = j; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<ll, ll>
#define vii vector<pii>
#define ff first
#define ss second

const ll M = 2e6 + 20;
vector<ll> fact(M, 1);
const ll N = 1e3 + 7;
const ll MOD = 1e9 + 7;

ll n, m;

vvi cap(N + 1, vi(N + 1, 0));
vvi cap1(N + 1, vi(N + 1, 0));
vi path;

ll bfs(ll s, ll t, vi adj[], vi &par, vvi &cap)
{
    fill(par.begin(), par.end(), -1);
    queue<pair<ll, ll>> q;
    par[s] = -2;
    vi ans(n + 1, 0);
    q.push({(ll)s, INT_MAX});
    while (!q.empty())
    {
        ll cur = q.front().ff;
        ll flow = q.front().ss;
        q.pop();
        for (auto i : adj[cur])
        {
            if (par[i] == -1 && cap[cur][i])
            {
                ll ansFlow = min((int)flow, cap[cur][i]);
                par[i] = cur;
                q.push({i, ansFlow});
                if (i == t)
                    return ansFlow;
            }
        }
    }
    return 0;
}

void dfs(ll s, vi adj[], vii G[], vi &vis)
{
    // cout << s << " - ";
    path.push_back(s);
    if (s == n)
        return;
    for (auto i : G[s])
    {
        // cout << i.ff << "; ";
        if (!vis[i.ss] && cap[s][i.ff] == 0)
        {
            vis[i.ss] = 1;
            dfs(i.ff, adj, G, vis);
            return;
        }
    }
}

void maxFlow(ll s, ll t, vi adj[], vii G[])
{
    vi par(n + 2, -1);
    ll newFlow = 0; 
    ll fAns = 0;
    while (newFlow = bfs(s, t, adj, par, cap))
    {
        // cout << newFlow << endl;
        fAns += newFlow;
        ll x = t;
        while (x != s)
        {
            ll p = par[x];
            cap[p][x] -= newFlow;
            cap[x][p] += newFlow;
            x = p;
        }
    }
    cout << fAns << "\n";
    vi vis(m + 1, 0);
    for (int i = 0; i < fAns; i++)
    {
        path.clear();
        dfs(1, adj, G, vis);
        cout << path.size() << "\n";
        for (auto j : path)
            cout << j << " ";
        cout << "\n";
    }
    
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vi adj[n + 1];
    vii G[n + 1];

    rep(i, 0, m)
    {
        ll x, y;
        cin >> x >> y;
        G[x].push_back({y, i + 1});
        adj[x].push_back(y);
        adj[y].push_back(x);
        cap[x][y] += 1;
        // cap1[x][y] = 1;
    }
    maxFlow(1, n, adj, G);
    return 0;
}