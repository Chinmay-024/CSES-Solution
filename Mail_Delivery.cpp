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

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vii adj[n + 1];

    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back({y, i});
        adj[y].push_back({x, i});
    }
    st.push(1);
    vi vis(m + 1, 0);
    vi path;
    rep(i, 1, n + 1)
    {
        if (adj[i].size() % 2 != 0)
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    while (!st.empty())
    {
        auto u = st.top();
        int f = 0;
        while (!adj[u].empty())
        {
            auto x = adj[u].back();
            adj[u].pop_back();
            if (!vis[x.ss])
            {
                vis[x.ss] = 1;
                st.push(x.ff);
                f = 1;
                break;
            }
        }
        if (!f)
        {
            path.push_back(u);
            st.pop();
        }
    }
    if (path.size() != m + 1)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        for (auto i : path)
        {
            cout << i << " ";
        }
    }

    return 0;
}