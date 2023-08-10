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

int n;

void dfs(int x, vi &dis, vi adj[], vi &down, int p)
{
    for (auto i : adj[x])
    {
        if (i == p)
            continue;
        dfs(i, dis, adj, down, x);
        down[x] += down[i];
        dis[x] += (dis[i] + down[i]);
    }
    down[x] += 1;
}

void dfs2(int x, vi &dis, vi adj[], vi &down, int p)
{
    for (auto i : adj[x])
    {
        if (i != p)
        {
            dis[i] = dis[x] - down[i] + n - down[i];
            dfs2(i, dis, adj, down, x);
        }
    }
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vi adj[n];
    rep(i, 0, n - 1)
    {
        ll x, y;
        cin >> x >> y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
    }
    vi dis(n, 0);
    vi down(n, 0);
    dfs(0, dis, adj, down, -1);
    dfs2(0, dis, adj, down, -1);
    rep(i, 0, n)
    {
        cout << dis[i] << " ";
    }
    return 0;
}