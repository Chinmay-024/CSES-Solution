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
    ll x;
    cin >> x;
    vi a(n);
    rep(i, 0, n)
            cin >>
        a[i];
    sort(a.begin(), a.end());
    vi done(n, 0);
    int i = 0;
    int ans = 0;
    int count = 0;
    int j = n - 1;
    while (i < j)
    {
        if (a[i] + a[j] <= x)
        {
            i++;
            j--;
            ans++;
            count += 2;
        }
        else
        {
            j--;
        }
    }
    cout << ans + n - count;
    return 0;
}