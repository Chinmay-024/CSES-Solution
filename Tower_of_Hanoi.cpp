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

ll k = 0;
vii ans;

void solve(int start, int helper, int final, int sticks)
{
    if (sticks == 0)
    {
        return;
    }
    solve(start, final, helper, sticks - 1);
    ans.push_back({start, final});
    k++;
    solve(helper, start, final, sticks - 1);
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    solve(1, 2, 3, n);
    cout << k << "\n";
    for (auto i : ans)
    {
        cout << i.ff << " " << i.ss << "\n";
    }
    return 0;
}