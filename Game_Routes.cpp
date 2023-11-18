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
const ll N = 1e5 + 7;
const ll MOD = 1e9 + 7;

vi adj[N];
ll n, m;
vi vis(N, 0);
vi p(N, -1);
vi dir(N, -1);
vi dp(N, 0);

void dfs(ll x)
{
    vis[x] = 1;
    for (auto i : adj[x])
    {
        if (!vis[i])
            dfs(i);
        dp[x] += dp[i] % MOD;
        dp[x] %= MOD;
    }
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    rep(i, 0, m)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    dp[n] = 1;
    dfs(1);
    cout << dp[1];
    return 0;
}