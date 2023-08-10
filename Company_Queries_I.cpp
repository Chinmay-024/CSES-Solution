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

void dfs(int x, vi adj[], vvi &dis, int p)
{
    for (auto i : adj[x])
    {
        if (i != p)
        {
            dis[i].push_back(x);
            rep(j, 0, dis[x].size())
            {
                // dis[i].insert(dis[i].begin(), dis[x][j]);
                dis[i].push_back(dis[x][j]);
            }
            dfs(i, adj, dis, x);
        }
    }
}
int up[18][(int)2e5 + 5];

int solve(int x, int k)
{
    for (int i = 0; i < 18; i++)
    {
        if ((k >> i) & 1)
        {
            x = up[i][x];
        }
    }
    return x;
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vi adj[n + 1];
    rep(i, 0, n - 1)
    {
        int x;
        cin >> x;
        up[0][i + 2] = x;
    }
    rep(i, 1, 18)
    {
        rep(j, 1, n + 1)
        {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }
    rep(i, 0, q)
    {
        int x, k;
        cin >> x >> k;
        int y = solve(x, k);
        cout << (y == 0 ? -1 : y) << "\n";
    }

    return 0;
}