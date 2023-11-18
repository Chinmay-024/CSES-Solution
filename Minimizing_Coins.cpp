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

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vi coins(n);
    rep(i, 0, n)
    {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    vi dp(x + 1, INT_MAX - 5);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0)
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
        }
    }
    cout << (dp[x] != (INT_MAX - 5) ? dp[x] : -1) << "\n";
    return 0;
}