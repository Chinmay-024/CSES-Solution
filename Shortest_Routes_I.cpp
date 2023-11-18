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
vector<ll> d;
vector<ll> p;

vector<vector<pair<ll, ll>>> adj(N);

void dijkstra(ll s)
{
    d.assign(n + 1, INF);
    p.assign(n + 1, -1);

    d[s] = 0;
    set<pair<ll, ll>> q;
    q.insert({0, s});
    while (!q.empty())
    {
        ll v = (*(q.begin())).ss;
        q.erase(q.begin());

        for (auto edge : adj[v])
        {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to])
            {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
    for (ll i = 1; i <= n; i++)
        cout << d[i] << " ";
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