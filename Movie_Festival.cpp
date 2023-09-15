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

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vii a(n);
    rep(i, 0, n)
    {
        int x, y;
        cin >> y >> x;
        a[i] = {x, y};
    }
    sort(a.begin(), a.end());

    int e = a[0].ff;
    ll count = 1;
    rep(i, 1, n)
    {
        int s = a[i].ss;
        if (s < e)
            continue;
        else
        {
            e = a[i].ff;
            count++;
        }
    }
    cout << count;
    return 0;
}