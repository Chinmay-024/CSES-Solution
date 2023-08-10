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

string t;
const ll M = 2e6 + 20;
vector<ll> fact(M, 1);
const int N = 1e5 + 7;
const ll MOD = 1e9 + 9;

bool valid(int i, vi &pi)
{
    // cout << i << pi[i - 1] << "\n";

    int j = pi[i - 1];
    if (j == i / 2)
        return true;
    else
        return false;
}

void lps()
{
    ll T = t.size();
    ll l = 0, r = 0;
    vi hash(T + 1, 0);
    vi power(T + 1, 0);
    power[0] = 1;
    rep(i, 1, T)
    {
        power[i] = (power[i - 1] * 9976) % MOD;
    }
    rep(i, 0, T)
    {
        hash[i + 1] = (hash[i] + (t[i] - 'a') * power[i]) % MOD;
    }
    for (ll i = 1; i <= T; i++)
    {
        bool ans = true;
        ll curIdx = 0;
        while (curIdx < T)
        {
            ll len = min(i, T - curIdx);
            if ((hash[curIdx + len] - hash[curIdx] + MOD) % MOD != ((hash[0 + len] % MOD - hash[0] % MOD + MOD) * power[curIdx]) % MOD)
            {
                ans = false;
                break;
            }
            else
            {
                curIdx += len;
            }
        }
        if (ans)
            cout << i << " ";
    }
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    lps();
    return 0;
}