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
    ll n;
    cin >> n;
    vi a(n);
    ll sum = 0;
    rep(i, 0, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    vi dp(sum + 1, 0);
    dp[0] = 1;
    ll ans = 0;
    rep(j, 0, n)
    {
        for (int i = sum; i >= 0; i--)
        {
            if (i - a[j] >= 0)
            {
                if (dp[i - a[j]] == 1)
                {
                    dp[i] = 1;
                }
            }
        }
        cout << "\n";
    }

    rep(i, 1, sum + 1)
    {
        if (dp[i] != 0)
            ans++;
    }
    cout << ans << "\n";
    rep(i, 1, sum + 1)
    {
        if (dp[i] != 0)
            cout << i << " ";
    }
    return 0;
}