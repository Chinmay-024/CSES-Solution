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
const ll N = 1e5 + 7;
const ll MOD = 1e9 + 7;

class Solution
{
public:
    void topo(int N, vector<ll> adj[])
    {
        queue<int> q;
        vector<int> indegree(N, 0);
        for (int i = 1; i < N; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        for (int i = 1; i < N; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if (topo.size() == N - 1)
        {
            for (auto i : topo)
                cout << i << " ";
        }
        else
            cout << "IMPOSSIBLE";
    }
};

int main()
{
    ll n, m;
    cin >> n >> m;
    n++;
    vi adj[n];
    rep(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    Solution obj;
    obj.topo(n, adj);

    return 0;
}