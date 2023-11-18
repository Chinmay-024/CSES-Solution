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

vi a(N, 0);

void build(ll node, ll st, ll en, vi &Tree)
{
    if (st == en)
    {
        Tree[node] = a[st];
        return;
    }
    ll mid = (st + en) / 2;
    build(2 * node, st, mid, Tree);
    build(2 * node + 1, mid + 1, en, Tree);
    Tree[node] = min(Tree[2 * node], Tree[2 * node + 1]);
}

ll query(ll node, ll st, ll en, ll a, ll b, vi &Tree)
{
    if (st > b || en < a)
        return 1e14;
    if (st >= a && en <= b)
        return Tree[node];
    ll mid = (st + en) / 2;
    ll left = query(2 * node, st, mid, a, b, Tree);
    ll right = query(2 * node + 1, mid + 1, en, a, b, Tree);
    return min(left, right);
}

void update(ll node, ll st, ll en, ll idx, ll val, vi &Tree)
{
    if (st == en)
    {
        // a[idx] = val;
        Tree[node] = val;
        return;
    }

    ll mid = (st + en) / 2;

    if (idx <= mid)
        update(2 * node, st, mid, idx, val, Tree);
    else
        update(2 * node + 1, mid + 1, en, idx, val, Tree);
    Tree[node] = min(Tree[2 * node], Tree[2 * node + 1]);
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    vi up(4 * N, 0);
    vi down(4 * N, 0);
    for (int i = 0; i < n; i++)
    {
        update(1, 0, n - 1, i, a[i] + i, up);
        update(1, 0, n - 1, i, a[i] - i, down);
    }
    rep(i, 0, q)
    {
        ll x;
        cin >> x;
        if (x == 1)
        {
            ll idx;
            ll u;
            cin >> idx >> u;
            update(1, 0, n - 1, idx - 1, u + idx - 1, up);
            update(1, 0, n - 1, idx - 1, u - idx + 1, down);
            a[idx] = u;
        }
        else
        {
            ll x;
            cin >> x;
            cout << min((query(1, 0, n - 1, 0, x - 1, down) + x - 1), (query(1, 0, n - 1, x - 1, n - 1, up) - x + 1)) << "\n";
        }
    }

    return 0;
}