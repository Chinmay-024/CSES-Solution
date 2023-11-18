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

vi adj[N];
ll n, m;
vi vis(N, 0);
ll ans = INT_MIN;
vi p(N, -1);
vi dir(N, -1);
vi dp(N, -1);

void dfs(int x)
{
    vis[x] = 1;
    for (auto i : adj[x])
    {
        if (!vis[i])
            dfs(i);
        if (dp[i] != -1 && dp[i] + 1 > dp[x])
        {
            dp[x] = dp[i] + 1;
            dir[x] = i;
        }
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
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    dp[n] = 1;
    dfs(1);

    if (dp[1] == -1)
        cout << "IMPOSSIBLE\n";
    else
    {
        cout << dp[1] << "\n";

        int node = 1;
        while (node != -1)
        {
            cout << node << " ";
            node = dir[node];
        }
    }
    return 0;
}