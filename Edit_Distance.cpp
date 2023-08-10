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
string a, b;
ll n, m;

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    n = a.size();
    m = b.size();
    vvi dp(n + 1, vi(m + 1, 0));
    rep(i, 0, n + 1)
    {
        dp[i][0] = i;
    }
    rep(i, 0, m + 1)
    {
        dp[0][i] = i;
    }
    rep(i, 1, n + 1)
    {
        rep(j, 1, m + 1)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min({1 + dp[i - 1][j - 1], dp[i - 1][j] + 1, 1 + dp[i][j - 1]});
        }
    }
    // rep(i, 0, n + 1)
    // {
    //     rep(j, 0, m + 1)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << dp[n][m];
    return 0;
}