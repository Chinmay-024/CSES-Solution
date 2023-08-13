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

string s;
ll n;

void manacher_algo()
{
    string t = "";

    string q1 = "#";
    for (int i = 0; i < n; i++)
    {
        t += (q1 + s[i]);
    }

    t += q1;
    int len = 2 * n + 1;
    // cout << t << "\n";
    vi p(2 * n + 1, 0);
    int l = 0, r = 0, c = 0, longestCentre = 0, longestlength = 0;
    for (int i = 0; i < len; i++)
    {
        int mirror = 2 * c - i;
        if (i < r)
        {
            p[i] = min(p[mirror], r - i);
        }
        int a = i - p[i] - 1;
        int b = i + p[i] + 1;
        while (a >= 0 && b < len && t[a] == t[b])
        {
            p[i]++;
            a--;
            b++;
        }
        if (p[i] > longestlength)
        {
            longestlength = p[i];
            longestCentre = i;
        }
        if (i + p[i] > r)
        {
            c = i;
            r = i + p[i];
        }
    }
    string q = t.substr(longestCentre - longestlength, 2 * longestlength + 1);
    string ans = "";
    for (int i = 0; i < q.size(); i++)
    {
        if (q[i] != '#')
            ans += q[i];
    }
    cout << ans;
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    n = s.size();
    manacher_algo();
    return 0;
}