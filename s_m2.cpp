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

string s, p;

void zAlgo()
{
    string t = p + "$" + s;
    int T = t.size();
    int l = 0, r = 0;
    vi z(T, 0);
    for (int i = 1; i < T; i++)
    {
        if (i < r)
        {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < T && t[i + z[i]] == t[z[i]])
        {
            z[i]++;
        }
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    int P = p.size();
    ll ans = 0;
    rep(i, 0, T)
    {
        if (z[i] == P)
        {
            ans++;
        }
    }
    cout << ans;
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> p;
    zAlgo();
    return 0;
}