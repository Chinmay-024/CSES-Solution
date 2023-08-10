#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i, j, n) for (int i = j; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second

const ll M = 2e6 + 20;
vector<ll> fact(M, 1);
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

int max1 = 0;
int max2 = 0;
int final = -1;

int dia_end = -1;
int dia_end2 = -1;

int ans = 0;

void solve(vi adj[], int x, int p, int y)
{
    if (max1 < y)
    {
        max1 = y;
        dia_end = x;
    }
    for (auto i : adj[x])
    {
        if (p != i)
        {
            solve(adj, i, x, y + 1);
        }
    }
}

void dfs(int x, int p, vi adj[], vi &dis, int y)
{
    dis[x] = y;
    if (max2 < y)
    {
        max2 = y;
        dia_end2 = x;
    }
    for (auto i : adj[x])
    {
        if (i != p)
        {
            dfs(i, x, adj, dis, y + 1);
        }
    }
}

void dfs2(int x, int p, vi adj[], vi &dis2, int y)
{
    dis2[x] = y;
    for (auto i : adj[x])
    {
        if (i != p)
        {
            dfs(i, x, adj, dis2, y + 1);
        }
    }
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "0";
        return 0;
    }
    vi dis = vi(n, 0);
    vi dis2 = vi(n, 0);
    vi adj[n + 1];
    rep(i, 0, n - 1)
    {
        int x, y;
        cin >> x >> y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
    }
    vvi dp(n + 1, vi(2, -1));
    solve(adj, 0, -1, 0);
    // cout << dia_end;
    dfs(dia_end, -1, adj, dis, 0);
    dfs2(dia_end2, -1, adj, dis2, 0);
    rep(i, 0, n)
    {
        cout << max(dis[i], dis2[i]) << " ";
    }
    return 0;
}