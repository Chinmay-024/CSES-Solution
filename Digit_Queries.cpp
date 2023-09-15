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
const ll MOD = 1e18 + 7;

ll power(ll x, ll n)
{
    ll ans = 1;
    while (n != 0)
    {
        if (n % 2 == 1)
            ans = (ans * x);
        x = (x * x);
        n /= 2;
    }
    return ans;
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q;
    cin >> q;
    rep(i, 0, q)
    {
        ll k;
        cin >> k;

        ll j = 0;
        while (1)
        {
            ll q = (9 * power(10, j)) * (j + 1);
            if (k > q)
                k -= q;
            else
                break;
            j++;
        }
        k--;
        j++;
        ll x = k / j;
        ll y = k % j;
        ll ans = power(10, j - 1) + x;
        string s = to_string(ans);
        cout << s[y] << endl;
    }
    return 0;
}