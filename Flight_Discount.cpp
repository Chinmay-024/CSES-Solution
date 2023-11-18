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
const ll N = 2e5 + 7;
const ll MOD = 1e9 + 7;

ll n, m;

const ll INF = 1e18;
vector<vector<ll>> d(N, vector<ll>(2, INF));
vector<ll> p;

vector<vector<pair<ll, ll>>> adj(N);

void dijkstra(ll s)
{
    p.assign(n + 1, -1);
    d[s][0] = 0;
    set<vi> q;
    q.insert({0, s, 0});
    while (!q.empty())
    {
        ll v = (*(q.begin()))[1];
        ll discount = (*(q.begin()))[2];
        q.erase(q.begin());

        for (auto edge : adj[v])
        {
            ll to = edge.first;
            ll len = edge.second;

            if (discount == 0)
            {
                if (d[v][discount] + len / 2 < d[to][1])
                {
                    q.erase({d[to][1], to, 1});
                    d[to][1] = d[v][0] + len / 2;
                    p[to] = v;
                    q.insert({d[to][1], to, 1});
                }
            }

            if (d[v][discount] + len < d[to][discount])
            {
                q.erase({d[to][discount], to, discount});
                d[to][discount] = d[v][discount] + len;
                p[to] = v;
                q.insert({d[to][discount], to, discount});
            }
        }
    }
    cout << d[n][1];
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll node1, node2, wt;
        cin >> node1 >> node2 >> wt;
        adj[node1].push_back({node2, wt});
    }
    dijkstra(1);
    return 0;
}