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

//  for (ll i = 2; i < M; i++)
//    fact[i] = (fact[i - 1] * i) % MOD;
// cout << fixed << setprecision(10);
// vvi vec( n , vi (m, 0));
// sort(arr, arr + n);
//__gcd(m, n)

ll power(ll x, ll n)
{
    ll ans = 1;
    while (n != 0)
    {
        if (n % 2 == 1)
            ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        n /= 2;
    }
    return ans % MOD;
}

ll nCr(ll n, ll r)
{
    if (r < 0 || r > n)
        return 0;
    ll x = power(fact[r], MOD - 2);
    ll y = power(fact[n - r], MOD - 2);
    x = (x * y) % MOD;
    return (fact[n] * x) % MOD;
}

ll up[20][(int)2e5 + 5];
ll dis[(int)2e5 + 5];

void dfs(int x, int p, vi adj[], int d)
{
    dis[x] = d;
    for (int i : adj[x])
    {
        if (i != p)
            dfs(i, x, adj, d + 1);
    }
}

int solve(int a, int b)
{
    if (dis[a] < dis[b])
        swap(a, b);
    int d = dis[a] - dis[b];
    for (int i = 0; i < 20; i++)
    {
        if (((d >> i) & 1) != 0)
            a = up[i][a];
    }
    // cout << d << " - " << a << "?" << b << "\n";
    if (a == b)
        return a;

    int at = a;
    int bt = b;
    for (int i = 19; i >= 0; i--)
    {
        if (up[i][at] != up[i][bt])
        {
            at = up[i][at];
            bt = up[i][bt];
        }
    }
    return up[0][at];
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vi adj[n + 1];
    rep(i, 0, n - 1)
    {
        int x;
        cin >> x;
        up[0][i + 2] = x;
        adj[x].push_back(i + 2);
    }

    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }
    // for (int i = 0; i < 20; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         cout << up[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    dfs(1, -1, adj, 0);
    rep(i, 0, q)
    {
        int a, b;
        cin >> a >> b;
        int y = solve(a, b);
        cout << (y == 0 ? 1 : y) << "\n";
    }
    return 0;
}