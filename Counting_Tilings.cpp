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
ll n, m;
int dp[1002][1 << 12];

void generate_masks(int cur_mask, int i, int next_mask, vector<int> &next_masks)
{
    if (i == n + 1)
    {
        next_masks.push_back(next_mask);
        return;
    }
    if ((1 << i) & cur_mask)
        generate_masks(cur_mask, i + 1, next_mask, next_masks);
    if (i != n)
    {
        if (((1 << i) & cur_mask) == 0 & ((1 << (i + 1)) & cur_mask) == 0)
            generate_masks(cur_mask, i + 2, next_mask, next_masks);
    }

    if (((1 << i) & cur_mask) == 0)
        generate_masks(cur_mask, i + 1, next_mask | (1 << i), next_masks);
}

int solve(int col, int mask)
{
    if (col == m + 1)
    {
        if (mask == 0)
            return 1;
        return 0;
    }
    if (dp[col][mask] != -1)
        return dp[col][mask];
    vi next_masks;
    int ans = 0;
    generate_masks(mask, 1, 0, next_masks);
    for (auto i : next_masks)
    {
        ans = (ans + solve(col + 1, i)) % MOD;
    }
    return dp[col][mask] = ans % MOD;
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << solve(1, 0);
    return 0;
}