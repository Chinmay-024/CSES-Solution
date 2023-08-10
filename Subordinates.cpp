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

int dfs(int x, vi &sub, vi adj[])
{
    if (sub[x] != -1)
        return sub[x];
    sub[x] = 0;
    for (auto i : adj[x])
    {
        sub[x] += dfs(i, sub, adj);
    }
    return sub[x] + 1;
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vi ans(n + 1, 0);
    vi adj[n + 1];
    rep(i, 0, n - 1)
    {
        int x;
        cin >> x;
        adj[x].push_back(i + 2);
    }
    vi sub(n + 1, -1);
    dfs(1, sub, adj);
    rep(i, 1, n + 1)
            cout
        << sub[i] << " ";
    return 0;
}