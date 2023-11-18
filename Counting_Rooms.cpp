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
vvi vis;
vector<string> grid;

void dfs(int i, int j)
{
    if (vis[i][j])
        return;
    vis[i][j] = 1;
    if (i + 1 < n && grid[i + 1][j] == '.')
        dfs(i + 1, j);
    if (j + 1 < m && grid[i][j + 1] == '.')
        dfs(i, j + 1);
    if (j - 1 >= 0 && grid[i][j - 1] == '.')
        dfs(i, j - 1);
    if (i - 1 >= 0 && grid[i - 1][j] == '.')
        dfs(i - 1, j);
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    rep(i, 0, n)
    {
        string s;
        cin >> s;
        grid.push_back(s);
    }
    vis = vvi(n, vi(m, 0));
    int ans = 0;
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                ans += 1;
                dfs(i, j);
            }
        }
    }
    cout << ans;
    return 0;
}