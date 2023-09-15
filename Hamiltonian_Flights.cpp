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

ll n, m;

vi vis(21, 0);
ll c = 0;
ll ans = 0;
vvi dp(20 + 2, vi((1 << 20) + 2, -1));

ll dfs(int x, ll mask, vi adj[])
{
    if (x == n - 1)
    {
        if (__builtin_popcount(mask) == n)
            return 1;
        else
            return 0;
    }

    if (dp[x][mask] != -1)
        return dp[x][mask];

    ll res = 0;
    for (auto i : adj[x])
    {
        if ((mask & (1 << i)) == 0)
            res = (res + dfs(i, mask | (1 << i), adj)) % MOD;
    }
    return dp[x][mask] = res;
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
        int x, y;
        cin >> x >> y;
        adj[--x].push_back(--y);
    }
    cout << dfs(0, (1 << 0), adj);
    return 0;
}
