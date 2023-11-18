#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i, j, n) for (ll i = j; i < n; i++)
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair<ll, ll>
#define vii vector<pii>
#define ff first
#define ss second

const ll M = 2e6 + 20;
vector<ll> fact(M, 1);
// const ll N = 1e5 + 7;
const ll MOD = 1e9 + 7;

stack<int> ans;
class Solution
{
private:
    bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[], vi &p)
    {
        vis[node] = 1;
        dfsVis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                p[it] = node;
                if (checkCycle(it, adj, vis, dfsVis, p))
                    return true;
            }
            else if (dfsVis[it])
            {
                ans.push(it);
                while (node != it)
                {
                    ans.push(node);
                    node = p[node];
                }
                ans.push(it);
                return true;
            }
        }
        p[node] = -1;
        dfsVis[node] = 0;
        return false;
    }

public:
    bool isCyclic(int N, vector<int> adj[])
    {
        int vis[N], dfsVis[N];

        for (int i = 0; i < N; i++)
        {
            vis[i] = 0;
            dfsVis[i] = 0;
        }

        vi p(N, -1);
        for (int i = 1; i < N; i++)
        {
            if (!vis[i])
            {
                if (checkCycle(i, adj, vis, dfsVis, p))
                {
                    cout << ans.size() << endl;
                    while (!ans.empty())
                    {
                        cout << ans.top() << " ";
                        ans.pop();
                    }
                    return true;
                }
            }
        }
        return false;
    }
};

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    ll V, m;
    cin >> V >> m;
    V++;
    vector<int> adj[V];
    rep(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        addEdge(adj, a, b);
    }

    Solution obj;
    if (!obj.isCyclic(V, adj))
        cout << "IMPOSSIBLE";

    return 0;
}