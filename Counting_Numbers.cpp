#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i, j, n) for (ll i = j; i < n; i++)
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair<ll, ll>
#define vii vector<pii>
#define ff first
#define ss second

const ll M = 2e6 + 20;
vector<ll> fact(M, 1);
const ll N = 1e5 + 7;
const ll MOD = 1e9 + 7;

ll dp[20][11][2][2];

ll solve(string A, ll idx, ll p_num, ll leading_zero, ll tight)
{
    if (idx == 0)
        return 1;
    if (dp[idx][p_num][leading_zero][tight] != -1)
        return dp[idx][p_num][leading_zero][tight];

    ll lb = 0;
    ll ub = tight ? A[A.size() - idx] - '0' : 9;
    ll ans = 0;
    for (ll i = lb; i <= ub; i++)
    {
        if (i == p_num && !leading_zero)
            continue;

        ans += solve(A, idx - 1, i, leading_zero & (i == 0), tight & (i == ub));
    }
    return dp[idx][p_num][leading_zero][tight] = ans;
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    string A = to_string(a - 1);
    string B = to_string(b);
    ll ans1 = solve(A, A.size(), -1, 1, 1);
    memset(dp, -1, sizeof(dp));
    ll ans2 = solve(B, B.size(), -1, 1, 1);
    cout << ans2 - ans1;
}