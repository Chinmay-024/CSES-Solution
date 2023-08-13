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
    ll n, k;
    cin >> n >> k;
    vi num(k);
    rep(i, 0, k)
    {
        cin >> num[i];
    }
    ll ans = 0;
    rep(i, 1, pow(2, k))
    {
        ll count = 1;
        ll c = 0;
        rep(j, 0, k)
        {
            if ((i >> j) & 1)
            {
                c++;
                if (count > n / num[j])
                {
                    count = n + 1;
                    break;
                }
                count *= num[j];
            }
        }
        ll q = n / count;
        if (c % 2 == 1)
            ans += q;
        else
            ans -= q;
        // cout << i << " " << c << " \n";
    }
    cout << ans;

    return 0;
}