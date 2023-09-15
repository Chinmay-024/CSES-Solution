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

//  for (ll i = 2; i < M; i++)
//    fact[i] = (fact[i - 1] * i) % MOD;
// cout << fixed << setprecision(10);
// vvi vec( n , vi (m, 0));
// sort(arr, arr + n);
//__gcd(m, n)

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x;
    cin >> n >> x;
    vii a(n);
    rep(i, 0, n)
    {
        int x;
        cin >> x;
        a[i] = {x, i};
    }
    sort(a.begin(), a.end());
    int l = 0;
    int h = n - 1;
    int f = 0;
    while (l < h)
    {
        ll q = a[l].ff + a[h].ff;
        if (q > x)
            h--;
        else if (q < x)
            l++;
        else
        {
            f = 1;
            break;
        }
    }
    if (f)
        cout << a[l].ss + 1 << " " << a[h].ss + 1 << endl;
    else
        cout << "IMPOSSIBLE\n";
    return 0;
}