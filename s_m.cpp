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
const ll N = 1e5 + 7;
const ll MOD = 1e9 + 9;

string a, b;

void robinKarp(string a, string b)
{
    ll A = a.size();
    ll B = b.size();
    ll x = max(A, B);
    vi power(x, 0);
    ll ans = 0;
    power[0] = 1;
    for (ll i = 1; i < x; i++)
    {
        power[i] = (power[i - 1] * 9973) % MOD;
    }
    vi h(A + 1, 0);
    rep(i, 0, A)
    {
        h[i + 1] = (h[i] + (a[i] - 'a' + 1) * power[i]) % MOD;
    }
    ll hash = 0ll;
    rep(i, 0, B)
    {
        hash = (hash + ((b[i] - 'a' + 1) * power[i]) % MOD) % MOD;
    }
    for (ll i = 0; i + B <= A; i++)
    {
        ll cur = (h[i + B] - h[i] + MOD) % MOD;
        if (cur == (power[i] * hash) % MOD)
            ans++;
    }
    cout << ans;
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    robinKarp(a, b);
    return 0;
}