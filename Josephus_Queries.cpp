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

ll solve(ll n, ll k)
{
    // cout << n << " " << k;
    if (n == 1)
        return 1;
    if (k <= (n + 1) / 2)
    {
        if (2 * k <= n)
            return 2 * k;
        else
            return ((2 * k) % n);
    }
    else
    {
        ll temp = solve(n / 2, k - ((n + 1) / 2));
        if (n % 2 != 0)
        {
            return 2 * temp + 1;
        }
        else
        {
            return 2 * temp - 1;
        }
    }
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
        ll n, k;
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }

    return 0;
}