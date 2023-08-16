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

ll a, b;

ll solve(ll a, ll b, vvi &dp)
{
    if (dp[a][b] != -1)
        return dp[a][b];
    if (a == b)
        return 0;
    else
    {
        ll ans = INT_MAX;
        for (int i = 1; i < a; i++)
        {
            ans = min(ans, solve(a - i, b, dp) + solve(i, b, dp) + 1);
        }
        for (int i = 1; i < b; i++)
        {
            ans = min(ans, solve(a, b - i, dp) + solve(a, i, dp) + 1);
        }
        return dp[a][b] = ans;
    }
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    vvi dp(a + 1, vi(b + 1, -1));
    cout << solve(a, b, dp);
    return 0;
}