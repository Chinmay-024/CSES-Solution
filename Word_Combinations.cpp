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

vi dp(5009, -1);
vector<string> words;

ll solve(ll i, string &s, int &n, vvi &keys)
{
    if (i == n)
        return 1;
    if (i > n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    ll ans = 0;
    for (int j = 0; j < keys[i].size(); j++)
    {
        if (i + keys[i][j] <= n)
        {
            ans = (ans % MOD + solve(i + keys[i][j], s, n, keys) % MOD) % MOD;
        }
    }
    return dp[i] = ans % MOD;
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;

    int n, k;
    cin >> s >> k;
    n = s.size();
    rep(i, 0, k)
    {
        string q;
        cin >> q;
        words.push_back(q);
    }
    vvi keys(n + 1);
    for (int i = 0; i < k; i++)
    {
        int index = 0;
        string substr = words[i];
        int q = substr.size();
        while ((index = s.find(substr, index)) != std::string::npos)
        {
            keys[index].push_back(q);
            index += 1;
        }
    }

    cout << solve(0, s, n, keys);

    return 0;
}