#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i, j, n) for (ll i = j; i < n; i++)
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair<ll, ll>
#define vii vector<pii>
#define ff first
#define ss second

const ll M = 2e6 + 20;
vector<ll> fact(M, 1);
const ll N = 1e5 + 7;
const ll MOD = 1e9 + 7;

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    ll n = s.size();
    vi a(26, 0);
    rep(i, 0, n)
    {
        a[s[i] - 'A']++;
    }
    ll od = 0;
    char ch;
    rep(i, 0, 26)
    {
        if (a[i] % 2 != 0)
        {
            od++;
            ch = (char)(i + 'A');
        }
    }
    if (n % 2 != 0)
    {
        if (od != 1)
        {
            cout << "NO SOLUTION";
            return 0;
        }
    }
    else
    {
        if (od != 0)
        {
            cout << "NO SOLUTION";
            return 0;
        }
    }
    string a1 = "", b1 = "";
    rep(i, 0, 26)
    {
        string str(a[i] / 2, (char)(i + 'A'));
        a1 += str;
        b1 = str + b1;
    }
    if (n % 2 == 0)
        cout << a1 + b1;
    else
        cout << a1 + ch + b1;

    return 0;
}