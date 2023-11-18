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
vi b(N, 0);
vi Tree(4 * N, 0);
vi Lazy(4 * N, 0);

void build(ll node, ll st, ll en)
{
    if (st == en)
    {
        Tree[node] = b[st];
        // cout << st << " - " << Tree[node] << " ";
        return;
    }
    ll mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);
    Tree[node] = max(Tree[2 * node], Tree[2 * node + 1]);
}

void push(ll node)
{
    Lazy[node * 2] += Lazy[node];
    Lazy[node * 2 + 1] += Lazy[node];
    Tree[node * 2] += Lazy[node];
    Tree[node * 2 + 1] += Lazy[node];
    Lazy[node] = 0;
}

void update(ll node, ll st, ll en, ll l, ll r, ll val)
{
    if (l > r)
        return;
    if (st == l && en == r)
    {
        Tree[node] += val;
        Lazy[node] += val;
        return;
    }
    push(node);
    ll mid = (st + en) / 2;
    update(2 * node, st, mid, l, min(mid, r), val);
    update(2 * node + 1, mid + 1, en, max(l, mid + 1), r, val);
    Tree[node] = max(Tree[node * 2 + 1], Tree[node * 2]);
}

ll query(ll node, ll st, ll en, ll l, ll r)
{
    // cout << st << " " << en << " " << l << " " << r << " " << Tree[node] << "\n";
    if (l > r)
        return (-1e14);
    if (st == l && en == r)
    {
        return Tree[node];
    }
    push(node);
    ll mid = (st + en) / 2;
    ll lt = -1e14, rt = -1e14;
    lt = query(2 * node, st, mid, l, min(mid, r));
    rt = query(2 * node + 1, mid + 1, en, max(l, mid + 1), r);
    // cout << st << " " << en << " " << max(lt, rt) << "\n";
    return max(lt, rt);
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    b[0] = 0;
    rep(i, 0, n)
    {
        cin >> a[i];
        b[i + 1] = a[i];
    }
    // cout << b[0] << " ";
    rep(i, 1, n + 1)
    {
        b[i] += b[i - 1];
        // cout << b[i] << " ";
    }
    cout << "\n";
    build(1, 0, n);
    rep(i, 0, q)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        if (x == 1)
        {
            update(1, 0, n, y, n, z - a[y - 1]);
            a[y - 1] = z;
        }
        else
            cout << query(1, 0, n, y - 1, z) - query(1, 0, n, y - 1, y - 1) << "\n";
    }
}