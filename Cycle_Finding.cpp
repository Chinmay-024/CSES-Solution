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

struct Edge
{
    ll a, b, cost;
};

ll n, m;
vector<Edge> edges;
const ll INF = 1e18;

void solve()
{
    vector<ll> d(n + 1);
    vector<ll> p(n + 1, -1);
    ll x;
    for (ll i = 0; i < n; ++i)
    {
        x = -1;
        for (Edge e : edges)
        {
            if (d[e.a] + e.cost < d[e.b])
            {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1)
    {
        cout << "NO\n";
    }
    else
    {
        for (ll i = 0; i < n; ++i)
            x = p[x];

        vector<ll> cycle;
        for (ll v = x;; v = p[v])
        {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for (ll v : cycle)
            cout << v << ' ';
        cout << endl;
    }
}
int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    rep(i, 0, m)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        Edge q;
        q.a = x;
        q.b = y;
        q.cost = z;
        edges.push_back(q);
    }
    solve();
    return 0;
}