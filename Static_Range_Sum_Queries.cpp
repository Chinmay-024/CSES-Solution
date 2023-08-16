#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i, j, n) for (int i = j; i < n; i++)
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second

const ll M = 2e6 + 20;
vector<ll> fact(M, 1);
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    vi x(n);
    cin >> x[0];
    rep(i, 1, n)
    {
        cin >> x[i];
        x[i] += x[i - 1];
    }
    rep(i, 0, q)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1)
            cout << x[b - 1];
        else
            cout << x[b - 1] - x[a - 2];
        cout << "\n";
    }
    return 0;
}