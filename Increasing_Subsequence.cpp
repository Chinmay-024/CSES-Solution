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
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    vi ans;
    int len = -1;
    for (int i = 0; i < n; i++)
    {
        if (len == -1 || a[i] > ans[len])
        {
            ans.push_back(a[i]);
            len++;
        }
        else
        {
            int idx = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[idx] = a[i];
        }
    }
    cout << ans.size();
    return 0;
}