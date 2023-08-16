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
const int N = 2e5 + 2;
const int MOD = 1e9 + 7;

ll n, m;
string s;

ll dp[2][2][N] = {0};
ll p[2] = {31, 37};
ll power[N][2] = {0};
ll inv[N][2] = {0};

ll expo(ll x, ll n)
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

void update(ll pt, ll t, ll idx, ll val)
{
    val += MOD;
    val %= MOD;
    for (int i = idx; i < n + 1; i += (i & (-i)))
    {
        dp[pt][t][i] += val % MOD;
        dp[pt][t][i] %= MOD;
    }
}

ll query(ll pt, ll t, ll idx)
{
    if (idx <= 0)
        return 0;
    ll ans = 0;
    for (int i = idx; i > 0; i -= (i & (-i)))
    {
        ans += dp[pt][t][i] % MOD;
        ans %= MOD;
    }
    return ans;
}

void init()
{
    for (int t = 0; t < 2; t++)
    {
        power[0][t] = 1;
        inv[0][t] = 1;
        for (int i = 1; i < N + 1; i++)
        {
            power[i][t] = (power[i - 1][t] % MOD * p[t] % MOD) % MOD;
            inv[i][t] = expo(power[i][t], MOD - 2);
        }

        for (int i = 0; i < n; i++)
        {
            dp[0][t][i + 1] = (s[i] - 'a' + 1) * power[n - i - 1][t];
            dp[1][t][i + 1] = (s[i] - 'a' + 1) * power[i][t];
        }
        for (int i = 1; i <= n; i++)
        {
            // update(0, t, i, (s[i] - 'a' + 1) * power[n - i - 1][t]);
            // update(1, t, i, (s[i] - 'a' + 1) * power[i][t]);
            int p = i + (i & (-i));
            if (p <= n)
            {
                dp[0][t][p] += dp[0][t][i];
                dp[1][t][p] += dp[1][t][i];
            }
        }
    }
}

bool isPalindrome(int a, int b)
{
    int i = 0;
    for (int i = 0; i < 2; i++)
    {
        ll f1 = (query(0, i, b) - query(0, i, a - 1)) % MOD;
        f1 *= inv[n - b][i] % MOD;
        f1 %= MOD;
        ll f2 = (query(1, i, b) - query(1, i, a - 1)) % MOD;
        f2 *= inv[a - 1][i] % MOD;
        f2 %= MOD;
        // cout << f1 << " " << f2 << "-----";
        if (f1 != f2)
            return false;
    }
    return true;
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> s;
    init();

    // rep(j, 0, n)
    // {
    //     cout << dp[1][0][j] << " ";
    // }
    // cout << "\n";
    // update(1, 0, 1, 1);
    // rep(j, 0, n)
    // {
    //     cout << dp[0][0][j] << " ";
    // }
    // cout << "\n";
    // cout << ((query(1, 0, 5) - query(1, 0, 2)) * inv[2][0]) % MOD << "\n";
    // cout << ((query(0, 0, 5) - query(0, 0, 2)) * inv[2][0]) % MOD << "\n";

    // cout << ((query(1, 1, 5) - query(1, 1, 2)) * inv[2][0]) % MOD << "\n";
    // cout << ((query(0, 1, 5) - query(0, 1, 2)) * inv[2][0]) % MOD << "\n";
    rep(i, 0, m)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int a;
            char b;
            cin >> a >> b;
            a--;
            int x = s[a] - 'a' + 1;
            int y = b - 'a' + 1;
            update(0, 1, a + 1, (y - x) * power[n - a - 1][0]);
            update(0, 0, a + 1, (y - x) * power[n - a - 1][1]);
            update(1, 1, a + 1, (y - x) * power[a][0]);
            update(1, 0, a + 1, (y - x) * power[a][1]);
            // rep(j, 0, n)
            // {
            //     cout << dp[1][0][j] << " ";
            // }
            // cout << "\n";
        }
        else
        {
            int a, b;
            cin >> a >> b;
            if (isPalindrome(a, b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}
