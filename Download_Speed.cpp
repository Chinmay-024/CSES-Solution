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
const ll N = 1001;
const ll MOD = 1e9 + 7;

ll n, m;
vvi cap(N + 1, vi(N + 1, 0));

ll bfs(ll s, ll t, vi adj[], vi &par)
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
            if (par[i] == -1 && cap[cur][i] > 0)
            {
                ll ansFlow = min(flow, cap[cur][i]);
                par[i] = cur;
                q.push({i, ansFlow});
                if (i == t)
                    return ansFlow;
            }
        }
    }
    return 0;
}

ll maxFlow(ll s, ll t, vi adj[])
{
    vi par(n + 2, -1);
    ll newFlow = 0;
    ll fAns = 0;
    while (newFlow = bfs(s, t, adj, par))
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
    return fAns;
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vi adj[n + 1];
    rep(i, 0, m)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back(y);
        adj[y].push_back(x);
        cap[x][y] += z;
    }
    cout << maxFlow(1, n, adj);

    return 0;
}