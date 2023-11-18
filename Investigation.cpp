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

ll n, m;
vii adj[N];

void dijkstra(int x)
{
    vi d(n, INT_MAX);
    vi r(n, 0);
    d[1] = 0;
    r[1] = 1;
    vi minF(n, 0);
    vi maxF(n, 0);
    set<pii> s;
    s.insert({0, x});
    while (!s.empty())
    {
        auto v = *(s.begin());
        s.erase(v);
        for (auto i : adj[v.ss])
        {m
            if (d[v.ss] + i.ss == d[i.ff])
            {
                r[i.ff] += r[v.ss];
                minF[i.ff] = min(minF[v.ss], minF[i.ss] + 1);
                maxF[i.ff] = max(maxF[v.ss], maxF[i.ss] + 1);
                continue;
            }
            if (d[v.ss] + i.ss < d[i.ff])
            {
                s.erase({d[i.ff], i.ff});
                d[i.ff] = d[v.ss] + i.ss;
                r[i.ff] = r[v.ss];
                minF[i.ff] = minF[v.ss] + 1;
                maxF[i.ff] = maxF[v.ss] + 1;
                s.insert({d[i.ff], i.ff});
            }
        }
    }
    cout << d[n - 1] << " " << r[n - 1] << " " << minF[n - 1] << " " << maxF[n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    n++;
    rep(i, 0, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    dijkstra(1);
    return 0;
}