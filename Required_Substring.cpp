#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i, j, n) for (ll i = j; i < n; i++)
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair<ll, ll>
#define vii vector<pii>
#define ff first
#define ss second

const ll M = 2e6 + 20;
vector<ll> fact(M, 1);
const ll N = 1e5 + 7;
const ll MOD = 1e9 + 7;

vi pi(1001, 0);

void kmp(string s, ll n)
{
    rep(i, 1, s.size())
    {
        ll j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j - 1];
        }
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
}

bool done[1001][101] = {false};
ll dp[1001][101] = {0};

ll solve(ll i, ll n, ll j, string s)
{
    if (done[i][j])
        return dp[i][j];
    done[i][j] = true;
    if (i == n)
        return dp[i][j] = ((j == s.size()) ? 1 : 0);
    if (j == s.size())
        return dp[i][j] = (26 * solve(i + 1, n, j, s) % MOD) % MOD;

    ll ans = 0;
    for (ll i1 = 0; i1 < 26; i1++)
    {
        ll t = j;
        while (true)
        {
            if ('A' + i1 == s[t])
            {
                t++;
                break;
            }
            else if (t)
            {
                t = pi[t - 1];
            }
            else
                break;
        }
        ans += solve(i + 1, n, t, s);
        ans %= MOD;
    }
    return dp[i][j] = ans % MOD;
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll m = s.size();
    kmp(s, n);
    cout << solve(0, n, 0, s);
    return 0;
}