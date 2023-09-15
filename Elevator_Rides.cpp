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

    ll n, m;
    cin >> n >> m;
    vi wt(n);
    rep(i, 0, n)
            cin >>
        wt[i];
    ll ans = 0;

    vii best((1 << n) + 1);
    best[0] = {1, 0};

    for (int s = 1; s < (1 << n); s++)
    {
        best[s] = {n + 1, 0};
        for (int i = 0; i < n; i++)
        {
            if (s & (1 << i))
            {
                auto ans = best[s ^ (1 << i)];
                if (ans.ss + wt[i] <= m)
                    ans.ss += wt[i];
                else
                {
                    ans.ff += 1;
                    ans.ss = wt[i];
                }
                best[s] = min(best[s], ans);
            }
        }
    }
    cout << best[(1 << n) - 1].ff << endl;

    return 0;
}