#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <utility>
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
stack<int> st;
vi vis(1e7, 0);
vi path;

void dfs(int x, vi adj[])
{
    while (adj[x].size())
    {
        int u = adj[x].back();
        adj[x].pop_back();
        dfs(u, adj);
    }
    path.push_back(x);
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vi adj[n + 1];
    vi in(n + 1, 0);
    vi out(n + 1, 0);
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
        out[x]++;
    }
    st.push(1);
    vi vis(m + 1, 0);
    int a = 0, b = 0, c = 0, s1 = 0, s2 = 0;
    rep(i, 1, n + 1)
    {
        if (in[i] == out[i])
            c++;
        if (in[i] - out[i] == 1)
        {
            b++;
            s2 = i;
        }
        if (in[i] - out[i] == -1)
        {
            a++;
            s1 = i;
        }
    }
    if (s1 != 1 || s2 != n)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    if (!(c == n - 2 && a == 1 && b == 1))
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    dfs(1, adj);
    reverse(path.begin(), path.end());
    if (path.size() != m + 1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (auto i : path)
        cout << i << " ";
    return 0;
}