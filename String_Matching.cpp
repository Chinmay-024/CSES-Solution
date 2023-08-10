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

ll n, m;
string ip, pat;

vi lp(string s)
{
    vi pi(m, 0);
    rep(i, 1, m)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j - 1];
        }
        if (s[i] == s[j])
        {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> ip >> pat;
    n = ip.size();
    m = pat.size();
    vi pi = (lp(pat));

    ll ans = 0;
    int i = 0, j = 0;
    while (i < n)
    {
        if (ip[i] == pat[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            ans++;
            j = pi[j - 1];
        }
        else if (i < n && ip[i] != pat[j])
        {
            if (j != 0)
                j = pi[j - 1];
            else
                i++;
        }
    }
    cout << ans;

    return 0;
}