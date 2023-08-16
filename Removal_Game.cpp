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

ll solve(int i, int n, vi &a, int j, vvi &dp)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i > j)
        return 0;
    if (i == j)
        return a[j];

    ll ans1 = a[i] + min(solve(i + 2, n, a, j, dp), solve(i + 1, n, a, j - 1, dp));
    ll ans2 = a[j] + min(solve(i + 1, n, a, j - 1, dp), solve(i, n, a, j - 2, dp));
    return dp[i][j] = max(ans1, ans2);
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    vvi dp(n + 1, vi(n + 1, -1));
    cout << solve(0, n, a, n - 1, dp);
    return 0;
}