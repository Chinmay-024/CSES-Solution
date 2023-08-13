#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i, j, n) for (int i = j; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<ll, ll>
#define vii vector<pii>
#define ff first
#define ss second

const ll M = 2e6 + 20;
vector<ll> fact(M, 1);
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

ll expo(ll a, ll p, ll mod = MOD)
{
    if (p == 0)
        return 1;
    else if (p == 1)
        return a;
    ll ans = 1;
    while (p > 0)
    {
        if (p & 1)
        {
            ans = (ans % mod * a) % mod;
        }
        a = (a % mod * a % mod) % mod;
        p >>= 1;
    }
    return ans;
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vii prime(n);
    int f = 0;
    ll maxi = 0;
    rep(i, 0, n)
    {
        ll x, y;
        cin >> x >> y;
        prime[i] = {x, y};
        maxi = max(x, expo(maxi, y));
        if (y % 2 != 0)
            f = 1;
    }
    ll div_count = 1;
    ll div_sum = 1;
    ll div_count2 = 1;
    ll div_product = 1;
    ll count1 = 0;
    rep(i, 0, n)
    {
        ll q = prime[i].ss;
        div_count = (div_count % MOD * (q + 1) % MOD) % MOD;
        div_sum = (div_sum % MOD * (expo(prime[i].ff, q + 1) % MOD - 1) % MOD * expo(prime[i].ff - 1, MOD - 2) % MOD) % MOD;
        // div_product = expo(div_product, q + 1) % MOD * expo(expo(prime[i].ff, q * (q + 1) / 2), div_count2) % MOD;
        if (q % 2 != 0 && count1)
        {
            div_count2 = (div_count2 % (MOD - 1) * ((q + 1) / 2) % (MOD - 1)) % (MOD - 1);
            count1++;
        }
        div_count2 = (div_count2 % (MOD - 1) * (q + 1) % (MOD - 1)) % (MOD - 1);
    }
    ll count = 0;
    if (f)
    {
        div_product = expo(maxi, div_count2);
    }
    else
    {
        maxi = sqrt(maxi);
        div_product = expo(maxi, div_count2);
    }
    cout << div_count << " " << div_sum << " " << div_product;
    return 0;
}