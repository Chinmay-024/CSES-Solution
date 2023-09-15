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

ll n;
int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vi a(n);
    rep(i, 0, n)
            cin >>
        a[i];
    sort(a.begin(), a.end());
    ll ans = 1;
    rep(i, 0, n)
    {
        if (a[i] > ans)
        {
            cout << ans;
            return 0;
        }
        else
        {
            ans += a[i];
        }
    }
    cout << ans;

    return 0;
}