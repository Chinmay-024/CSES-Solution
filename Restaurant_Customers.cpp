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

int n;

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vi a(2 * n);
    unordered_map<int, int> st;
    for (int i = 0; i < 2 * n; i += 2)
    {
        cin >> a[i] >> a[i + 1];
        st[a[i]] = 1;
    }
    sort(a.begin(), a.end());
    int count = 0;
    int ans = 0;
    rep(i, 0, 2 * n)
    {
        if (st[a[i]] == 1)
            count++;
        else
            count--;
        ans = max(ans, count);
    }
    cout << ans;
    return 0;
}