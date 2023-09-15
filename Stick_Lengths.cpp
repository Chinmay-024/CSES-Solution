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
    ll sum = 0ll;
    ll sum2 = 0ll;
    ll ans = 0ll;
    ll ans2 = 0ll;
    rep(i, 0, n)
    {
        int x;
        cin >> x;
        a[i] = x;
    }
    sort(a.begin(), a.end());
    ans = a[n / 2];
    ans2 = a[n / 2 - 1];
    rep(i, 0, n)
    {
        sum += abs(ans - a[i]);
        sum2 += abs(ans2 - a[i]);
    }
    cout << min(sum, sum2);
    return 0;
}