#pragma comment(linker, "/STACK:20000000") // Adjust the stack size as needed

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

vi dp(1e6 + 5, -1);

int solve(int n)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int m = n;
    int ans = INT_MAX - 5;
    while (n > 0)
    {
        int x = n % 10;
        if (x != 0)
            ans = min(ans, solve(m - x) + 1);
        n = n / 10;
    }
    return dp[m] = ans;
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int ans = 0;
    cout << solve(n);
    return 0;
}