#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i, j, n) for (ll i = j; i < n; i++)
#define vi vector<ll>
#define pii pair<ll, ll>
#define vii vector<pii>
#define vvi vector<vii>
#define ff first
#define ss second

const ll M = 2e6 + 20;
vector<ll> fact(M, 1);
const ll N = 1e5 + 7;
const ll MOD = 1e9 + 7;

ll n;

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    map<ll, ll> mp;
    vi a(n), b(n), c(n);
    rep(i, 0, n)
    {
        cin >> a[i] >> b[i] >> c[i];
        b[i]++;
        mp[a[i]];
        mp[b[i]];
    }
    ll idx = 0;
    for (auto i : mp)
        mp[i.ff] = idx++;

    vvi projects(idx);
    for (ll i = 0; i < n; i++)
    {
        projects[mp[b[i]]].push_back({mp[a[i]], c[i]});
    }
    vi dp(idx, 0);
    rep(i, 0, idx)
    {
        if (i != 0)
            dp[i] = dp[i - 1];
        for (auto j : projects[i])
            dp[i] = max(dp[i], dp[j.ff] + j.ss);
    }
    cout << dp[idx - 1];
    return 0;
}