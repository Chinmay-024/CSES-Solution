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

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<string> a(power(2, n) + 2);
    a[0] = "0";
    a[1] = "1";
    rep(i, 2, n + 1)
    {
        ll z = power(2, i);
        ll q = power(2, i - 1) - 1;
        rep(j, power(2, i - 1), z)
        {
            a[j] = a[q];
            a[j] = "1" + a[j];
            a[q] = "0" + a[q];
            q--;
        }
    }
    rep(i, 0, power(2, n)) cout << a[i] << endl;
    return 0;
}