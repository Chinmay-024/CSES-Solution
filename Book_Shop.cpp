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
    vii h(n);
    rep(i, 0, n)
    {
        cin >> h[i].ff;
    }
    rep(i, 0, n)
    {
        cin >> h[i].ss;
    }
    vi dp(x + 1, 0);
    dp[0] = 0;
    sort(h.begin(), h.end());
    for (int i = 1; i <= n; i++)
    {
        for (int j = x; j >= 0; j--)
        {
            if (j - h[i - 1].ff >= 0)
            {
                dp[j] = max(dp[j], h[i - 1].ss + dp[j - h[i - 1].ff]);
            }
        }
    }
    cout << dp[x] << "\n";
    return 0;
}