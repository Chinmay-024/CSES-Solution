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
const ll MOD = 1e9 + 7;

ll exp(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b = b >> 1;
        // cout << a << " " << b << endl;
    }
    return ans % MOD;
}

// ll exp(ll a, ll b)
// {
//     if (b == 0)
//         return 1;
//     if (b == 1)
//         return a;
//     if (b == 2)
//         return (a * a) % MOD;
//     if (b % 2 == 0)
//     {
//         ll x = exp(a, b / 2) % MOD;
//         return (x * x) % MOD;
//     }
//     else
//     {
//         return (a * exp(a, b - 1)) % MOD;
//     }
// }

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int qi = 0; qi < t; qi++)
    {
        ll a, b;
        cin >> a >> b;
        cout << exp(a, b) << "\n";
    }
    return 0;
}