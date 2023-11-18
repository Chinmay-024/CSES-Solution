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
ll n;
vi num((ll)2e5 + 2, 0);
vi sol((ll)2e5 + 2, 0);

ll dfs(int x, int p, vi adj[])
{
    ll ans = 0;
    for (auto i : adj[x])
    {
        if (i != p)
            ans += dfs(i, x, adj);
    }
    num[x] = ans;
    return num[x] + 1;
}

void dfs2(int x, int p, vi adj[])
{
    ll ans = 0;
    bool tmp = true;
    // cout << x << " ";
    if (p != -1)
    {
        ans += n - num[x] - 1;
        // num[x] += ans;
        if (ans > n / 2)
            tmp = false;
    }
    for (auto i : adj[x])
    {
    // cout << "\n";
    for (auto i : adj[x])
        if (i != p)
        {
            if (num[i] + 1 > n / 2)
                tmp = false;
            // cout << i << " " << num[i] << " ";
        }
    }
    // cout << "\n";
    for (auto i : adj[x])
    {
        if (i != p)
        {
            dfs2(i, x, adj);
        }
    }
    sol[x] = tmp ? 1 : 0;
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vi adj[n + 1];
    rep(i, 0, n - 1)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1, adj);
    // rep(i, 1, n + 1)
    //         cout
    //     << num[i] << " ";
    dfs2(1, -1, adj);
    // cout << "\n";
    // rep(i, 1, n + 1)
    //         cout
    //     << num[i] << " ";
    rep(i, 1, n + 1)
    {
        if (sol[i])
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}