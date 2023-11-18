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
const int N = 1e3 + 7;
const int MOD = 1e9 + 7;

vector<string> forest(N);
ll n, q;
vvi dp(N, vi(N, 0));

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    rep(i, 0, n)
    {
        cin >> forest[i];
    }

    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            if ((forest[i][j] == '*'))
                dp[i][j] += 1;
            if (i > 0)
                dp[i][j] += dp[i - 1][j];
            if (j > 0)
                dp[i][j] += dp[i][j - 1];
            if (i > 0 && j > 0)
                dp[i][j] -= dp[i - 1][j - 1];
        }
    }
    rep(j, 0, q)
    {
        ll y1, x1, y2, x2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll ans = 0;
        --y1;
        --x1;
        --y2;
        --x2;
        ans += dp[x2][y2];
        // cout << ans << " ";
        if (y1 > 0)
        {
            ans -= dp[x2][y1 - 1];
        }
        if (x1 > 0)
        {
            ans -= dp[x1 - 1][y2];
        }
        if (x1 > 0 && y1 > 0)
        {
            ans += dp[x1 - 1][y1 - 1];
        }
        cout << ans << "\n";
    }
    return 0;
}