#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
vector<vector<int>> adj(MAXN);
vector<int> color(MAXN, -1);
int fault = 0;

void DFS(int node, int c)
{
    color[node] = c;
    for (auto child : adj[node])
    {
        if (color[child] == -1)
        {
            DFS(child, c xor 1);
        }
        else
        {
            if (color[child] == c)
            {
                fault = 1;
                return;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            DFS(i, 0);
            if (fault)
                break;
        }
    }
    if (fault)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << color[i] + 1 << " ";
    }
    return 0;
}