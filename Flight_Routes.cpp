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

ll n, m, k;
vii adj[N];

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    rep(i, 0, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    ll CNT[n + 1];
    memset(CNT, 0, sizeof(CNT));
    priority_queue<pii, vii, greater<pii>> pq;
    pq.push({0, 1});
    vi v;
    while (!pq.empty() && CNT[n] < k)
    {
        auto c = pq.top();
        pq.pop();
        if (c.ss == n)
            v.push_back(c.ff);
        CNT[c.ss] += 1;
        if (CNT[c.ss] <= k)
        {
            for (auto i : adj[c.ss])
            {
                pq.push({i.ss + c.ff, i.ff});
            }
        }
    }
    // sort(v.begin(), v.end());
    for (auto i : v)
        cout << i << " ";
    return 0;
}