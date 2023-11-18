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

int n;
vector<vector<int>> adj(N);
vector<bool> visited;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v, int par)
{
    visited[v] = true;
    for (int u : adj[v])
    {
        if (u == par)
            continue;
        if (visited[u])
        {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    return false;
}

void find_cycle()
{
    visited.assign(n, false);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++)
    {
        if (!visited[v] && dfs(v, parent[v]))
            break;
    }

    if (cycle_start == -1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);

        cout << cycle.size() << endl;
        for (int v : cycle)
            cout << v + 1 << " ";
        cout << endl;
    }
}
int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        adj[--node1].push_back(--node2);
        adj[node2].push_back(node1);
    }
    find_cycle();
    return 0;
}