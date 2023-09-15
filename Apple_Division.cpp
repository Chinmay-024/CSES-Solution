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
    ll k = (ceil)(log2(n));
    ll minAns = INT_MAX;
    rep(i, 1, power(2, n))
    {
        ll ans = 0;
        rep(j, 0, n)
        {

            if ((i >> j) & 1)
            {
                ans += a[j];
            }
        }
        minAns = min(minAns, abs((sum - ans) - ans));
    }
    cout << minAns << endl;

    return 0;
}