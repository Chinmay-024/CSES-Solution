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

vvi dp(9, vi(9, 0));
ll ans = 0;

void solve(int x, int y, string &s, int i)
{
    if (dp[x][y] == 1)
        return;

    if ((dp[x][y - 1] && dp[x][y + 1]) &&
        (!dp[x - 1][y] && !dp[x + 1][y]))
        return;
    if ((dp[x - 1][y] && dp[x + 1][y]) &&
        (!dp[x][y - 1] && !dp[x][y + 1]))
        return;

    if (x == 7 && y == 1)
    {
        if (i == 48)
            ans++;
        return;
    }
    if (i == 48 && (x != 7 || y != 0))
        return;

    dp[x][y] = 1;
    if (s[i] == '?')
    {
        solve(x - 1, y, s, i + 1);
        solve(x + 1, y, s, i + 1);
        solve(x, y - 1, s, i + 1);
        solve(x, y + 1, s, i + 1);
        dp[x][y] = 0;
    }
    else
    {
        switch (s[i])
        {
        case 'U':
            solve(x - 1, y, s, i + 1);
            break;
        case 'D':
            solve(x + 1, y, s, i + 1);
            break;
        case 'L':
            solve(x, y - 1, s, i + 1);
            break;
        case 'R':
            solve(x, y + 1, s, i + 1);
            break;
        }
        dp[x][y] = 0;
    }
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    for (int i = 0; i < 9; i++)
    {
        dp[0][i] = 1;
        dp[8][i] = 1;
        dp[i][0] = 1;
        dp[i][8] = 1;
    }
    solve(1, 1, s, 0);
    cout << ans;
    return 0;
}