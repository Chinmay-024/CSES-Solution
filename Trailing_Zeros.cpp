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
const ll MOD = 1e12 + 7;

//  for (ll i = 2; i < M; i++)
//    fact[i] = (fact[i - 1] * i) % MOD;
// cout << fixed << setprecision(10);
// vvi vec( n , vi (m, 0));
// sort(arr, arr + n);
//__gcd(m, n)

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

ll nCr(ll n, ll r)
{
    if (r < 0 || r > n)
        return 0;
    ll x = power(fact[r], MOD - 2);
    ll y = power(fact[n - r], MOD - 2);
    x = (x * y) % MOD;
    return (fact[n] * x) % MOD;
}

int main()
{
    ll n;
    cin >> n;
    ll count10 = 0;
    rep(i, 1, 32)
    {
        if (n / power(5, i) == 0)
            break;
        else
            count10 += ((n / power(5, i)));
    }
    ll count2 = 0;
    rep(i, 1, 32)
    {
        if (n / power(2, i) == 0)
            break;
        else
            count2 += ((n / power(2, i)));
    }
    // rep(i, 1, 30)
    // {
    //     if (n % power(5, i) == 0)
    //         break;
    //     else
    //         count10 += (n % power(5, i) == 0) ? i : 0;
    // }
    cout << min(count2, count10);
}