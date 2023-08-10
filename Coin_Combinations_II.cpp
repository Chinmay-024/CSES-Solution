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

//  for (ll i = 2; i < M; i++)
//    fact[i] = (fact[i - 1] * i) % MOD;
// cout << fixed << setprecision(10);
// vvi vec( n , vi (m, 0));
// sort(arr, arr + n);
//__gcd(m, n)

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vi c(n);
    rep(i, 0, n)
    {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    vi dp(x + 1, 0);
    dp[0] = 1;

    for (int j = 0; j < n; j++)
    {
        for (int i = 1; i <= x; i++)
        {
            if (i - c[j] >= 0)
                dp[i] = (dp[i] % MOD + dp[i - c[j]] % MOD) % MOD;
        }
    }
    cout << dp[x] % MOD << endl;

    return 0;
}