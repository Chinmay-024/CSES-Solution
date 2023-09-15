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
vi Tree(4 * N, 0);

void build(ll node, ll st, ll en)
{
    if (st == en)
    {
        Tree[node] = a[st];
        return;
    }
    ll mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);
    Tree[node] = Tree[2 * node] xor Tree[2 * node + 1];
}

ll query(ll node, ll st, ll en, ll a, ll b)
{
    if (st > b || en < a)
        return 0;
    if (st >= a && en <= b)
        return Tree[node];
    ll mid = (st + en) / 2;
    ll left = query(2 * node, st, mid, a, b);
    ll right = query(2 * node + 1, mid + 1, en, a, b);
    return left xor right;
}

void update(ll node, ll st, ll en, ll idx, ll val)
{
    if (st == en)
    {
        a[idx] = val;
        Tree[node] = val;
        return;
    }

    ll mid = (st + en) / 2;

    if (idx <= mid)
        update(2 * node, st, mid, idx, val);
    else
        update(2 * node + 1, mid + 1, en, idx, val);
    Tree[node] = Tree[2 * node] xor Tree[2 * node + 1];
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
    build(1, 0, n - 1);
    rep(i, 0, q)
    {
        ll a, b;
        cin >> a >> b;
        cout << query(1, 0, n - 1, a - 1, b - 1) << "\n";
    }

    return 0;
}