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

ll up[20][(ll)2e5 + 5];
ll dis[(ll)2e5 + 5];

void dfs(int x, int p, vi adj[], int y)
{
    dis[x] = y;
    up[0][x] = p;
    for (auto i : adj[x])
    {
        if (i != p)
        {
            dfs(i, x, adj, y + 1);
        }
    }
}

int solve(int a, int b)
{
    if (dis[a] < dis[b])
        swap(a, b);
    int d = dis[a] - dis[b];
    for (int i = 0; i < 20; i++)
    {
        if ((d >> i) & 1)
        {
            a = up[i][a];
        }
    }
    if (a == b)
        return d;
    int at = a;
    int bt = b;
    for (int i = 19; i >= 0; i--)
    {
        at = up[i][a];
        bt = up[i][b];
        if (at != bt)
        {
            a = at;
            b = bt;
            d += (pow(2, i) * 2);
        }
    }
    return d + 2;
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    vi adj[n + 1];
    rep(i, 0, n - 1)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, -1, adj, 0);
    up[0][1] = 0;
    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }
    rep(i, 0, q)
    {
        int a, b;
        cin >> a >> b;
        cout << solve(a, b) << "\n";
    }
    return 0;
}