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

//  for (ll i = 2; i < M; i++)
//    fact[i] = (fact[i - 1] * i) % MOD;
// cout << fixed << setprecision(10);
// vvi vec( n , vi (m, 0));
// sort(arr, arr + n);
//__gcd(m, n)

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll sum = n % MOD;
    for (int i = 2; i * i <= n; i++)
    {
        sum = (sum + ((i % MOD) * ((n / i) % MOD) % MOD));
        if ((n / i) > sqrt(n))
            sum = (sum % MOD + (((i - 1) % MOD) * ((n / i) % MOD) % MOD));
    }
    ll q = sqrt(n);

    sum = sum + ((n % MOD) * ((n + 1) % MOD) / 2) % MOD;
    sum = sum - ((q % MOD) * ((q + 1) % MOD) / 2) % MOD;

    cout << sum;
    return 0;
}
