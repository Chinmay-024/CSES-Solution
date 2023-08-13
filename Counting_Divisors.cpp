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
const int N = 1e6 + 2;
const int MOD = 1e9 + 7;

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    vi ans(1e6 + 2, 2);
    ans[1] = 1;
    for (int i = 2; i < N; i++)
    {
        for (int j = i * 2; j < N; j += i)
        {
            ans[j]++;
        }
    }
    for (int qi = 0; qi < t; qi++)
    {
        ll x;
        cin >> x;
        cout << ans[x] << "\n";
    }
    return 0;
}