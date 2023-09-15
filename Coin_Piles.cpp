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

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    rep(i, 0, n)
    {
        ll a, b;
        cin >> a >> b;
        if (max(a, b) > 2 * min(a, b))
            cout << "NO\n";
        else
        {
            if ((a + b) % 3 == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}