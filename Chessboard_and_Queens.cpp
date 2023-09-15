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

ll power(ll x, ll n)
{
    ll ans = 1;
    while (n != 0)
    {
        if (n % 2 == 1)
            ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        n /= 2;
    }
    return ans % MOD;
}

ll ans = 0;

bool valid(vector<string> &a, int row, int col, vvi &sol)
{
    if (a[row][col] == '*')
        return false;
    int r = row, c = col;
    rep(i, 0, row)
    {
        if (sol[i][col] == 1)
            return false;
    }
    while (r >= 0 && c >= 0)
    {
        if (sol[r][c] == 1)
            return false;
        r--;
        c--;
    }

    r = row;
    c = col;
    while (r >= 0 && c < 8)
    {
        if (sol[r][c] == 1)
            return false;
        r--;
        c++;
    }
    return true;
}

void solve(vector<string> &a, int row, vvi &sol)
{
    if (row == 8)
    {
        // rep(i, 0, 8)
        // {
        //     rep(j, 0, 8) { cout << sol[i][j] << " "; }
        //     cout << "\n";
        // }
        ans++;
        // cout << " \n\n";
        return;
    }
    rep(i, 0, 8)
    {
        if (valid(a, row, i, sol))
        {
            sol[row][i] = 1;
            solve(a, row + 1, sol);
            sol[row][i] = -1;
        }
    }
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> a(8);
    rep(i, 0, 8)
            cin >>
        a[i];
    vvi sol(8, vi(8, -1));
    solve(a, 0, sol);
    cout << ans;
    return 0;
}