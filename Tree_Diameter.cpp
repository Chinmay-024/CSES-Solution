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

int ans = 0;

int solve(vi adj[], vvi &dp, int x, int parent)
{
    int max1 = 0;
    int max2 = 0;
    for (auto i : adj[x])
    {
        if (i != parent)
        {
            int dia = solve(adj, dp, i, x);
            if (dia >= max1)
            {
                max2 = max(max2, max1);
                max1 = dia;
            }
            else
            {
                if (dia >= max2)
                    max2 = dia;
            }
        }
    }
    ans = max(ans, max1 + max2);
    return max1 + 1;
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    // if (n == 1)
    // {
    //     cout << 0 << endl;
    //     return 0;
    // }
    vi adj[n + 1];
    rep(i, 0, n - 1)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vvi dp(n + 1, vi(2, -1));
    solve(adj, dp, 1, -1);
    cout << ans << "\n";
    return 0;
}