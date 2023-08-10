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

void solve(vi adj[], vvi &dp, int x, int parent)
{
    if (dp[x][0] == -1)
    {
        dp[x][0] = 0;
        for (auto i : adj[x])
        {
            if (i != parent)
            {
                solve(adj, dp, i, x);
                dp[x][0] += max(dp[i][0], dp[i][1]);
            }
        }
    }
    if (dp[x][1] == -1)
    {
        dp[x][1] = 0;
        for (auto i : adj[x])
        {
            if (i != parent)
            {
                solve(adj, dp, i, x);
                dp[x][1] = max(dp[x][1], dp[i][0] + 1 + dp[x][0] - max(dp[i][1], dp[i][1]));
            }
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

        cout << 0 << endl;
        return 0;
    }
    vi adj[n];
    rep(i, 0, n - 1)
    {
        int x, y;
        cin >> x >> y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
    }
    vvi dp(n + 1, vi(2, -1));
    solve(adj, dp, 1, -1);
    cout << max(dp[1][0], dp[1][1]) << endl;
    return 0;
}