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

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    if ((n * (n + 1)) % 4 != 0)
    {
        cout << 0;
        return 0;
    }
    ll ans = (n * (n + 1)) / 4;
    vi dp(ans + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = ans; j >= 0; j--)
        {
            if (j - i >= 0)
            {
                dp[j] += dp[j - i] % MOD;
                dp[j] %= MOD;
            }
            else
                break;
        }
        // for (int i = 0; i <= ans; i++)
        //     cout << dp[i] << " ";
        // cout << "\n";
    }
    cout << (dp[ans] % MOD * 500000004 % MOD) % MOD;
    return 0;
}
// 1 2 3 4 5 6 7