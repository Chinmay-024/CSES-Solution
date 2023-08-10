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

//  for (ll i = 2; i < M; i++)
//    fact[i] = (fact[i - 1] * i) % MOD;
// cout << fixed << setprecision(10);
// vvi vec( n , vi (m, 0));
// sort(arr, arr + n);
//__gcd(m, n)

ll power(ll x, ll n)
{
    ll ans = 1;
    while (n != 0)
    {
        if (n % 2 == 1)
            ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        n /= 2;
    }
    return ans % MOD;
}

ll nCr(ll n, ll r)
{
    if (r < 0 || r > n)
        return 0;
    ll x = power(fact[r], MOD - 2);
    ll y = power(fact[n - r], MOD - 2);
    x = (x * y) % MOD;
    return (fact[n] * x) % MOD;
}
int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<char>> matrix(n, vector<char>(n));
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            cin >> matrix[i][j];
        }
    }
    vvi dp(n + 1, vi(n + 1, 0));
    dp[0][0] = 0;
    rep(i, 0, n)
    {
        if (matrix[0][i] != '*')
            dp[0][i] = 1;
        else
            break;
    }
    rep(i, 0, n)
    {
        if (matrix[i][0] != '*')
            dp[i][0] = 1;
        else
            break;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == '*')
                continue;
            if (matrix[i - 1][j] != '*')
                dp[i][j] += dp[i - 1][j] % MOD;

            if (matrix[i][j - 1] != '*')
                dp[i][j] += dp[i][j - 1] % MOD;
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n - 1][n - 1] << endl;
    return 0;
}