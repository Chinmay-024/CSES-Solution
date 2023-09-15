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

const ll M = 2e5 + 20;
vector<ll> fact(M, 1);
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

ll n, k1, k2;
vector<bool> processed((int)2e5 + 2, false);
vi subtree((int)2e5 + 2, 0);
int count1[(int)2e5 + 2];
ll ans = 0;
int mx_depth;

int getSubtreeSize(int x, int p, vi adj[])
{
    subtree[x] = 1;
    for (auto i : adj[x])
    {
        if (!processed[i] && i != p)
            subtree[x] += getSubtreeSize(i, x, adj);
    }
    return subtree[x];
}

int getCentroid(int x, int p, vi adj[], int desired)
{
    for (auto i : adj[x])
    {
        if (!processed[i] && i != p && subtree[i] >= desired)
            return getCentroid(i, x, adj, desired);
    }
    return x;
}

void get_count(int x, int p, int depth, vi adj[], bool fill, ll prev, bool cond)
{
    if (depth > k2)
        return;

    mx_depth = max(mx_depth, depth);
    if (fill)
    {
        count1[depth]++;
        if(depth>=k1 && depth<=k2)

    }
    else
    {
        if (!cond)
        {
            for (int i = k2 - depth; i >= max(0ll, k1 - depth); i--)
                prev += count1[i];
            ans += prev;
            cond = true;
        }
        else
        {
            prev -= count1[k2 - depth + 1];
            prev += (k1 - depth >= 0) ? count1[k1 - depth] : 0;
            ans += prev;
        }
    }
    for (auto i : adj[x])
    {
        if (i != p && !processed[i])
        {
            get_count(i, x, depth + 1, adj, fill, prev, cond);
        }
    }
}

void solve(int x, vi adj[])
{
    int desired = getSubtreeSize(x, -1, adj);
    int centroid = getCentroid(x, -1, adj, desired >> 1);
    processed[centroid] = true;
    mx_depth = 0;
    for (auto i : adj[centroid])
    {
        bool cond = false;
        ll tmp = 0;
        if (!processed[i])
        {
            ll prev = 0;
            get_count(i, centroid, 1, adj, false, prev, cond);
            get_count(i, centroid, 1, adj, true, prev, cond);
        }
    }
    fill(count1 + 1, mx_depth + count1 + 1, 0);
    for (auto i : adj[centroid])
    {
        if (!processed[i])
        {
            solve(i, adj);
        }
    }
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k1 >> k2;

    vi adj[n + 2];
    count1[0] = 1;
    rep(i, 0, n - 1)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    solve(1, adj);
    cout << ans;
    return 0;
}