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

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    if ((n * (n + 1)) % 4 != 0)
        cout << "NO";
    else
    {
        cout << "YES\n";
        stack<int> s;
        stack<int> s1;
        ll ans = (n * (n + 1)) / 4;
        for (int i = n; i >= 1; i--)
        {
            if (ans >= i)
            {
                ans -= i;
                s1.push(i);
            }
            else
                s.push(i);
        }
        cout << s1.size() << "\n";
        while (!s1.empty())
        {
            cout << s1.top() << " ";
            s1.pop();
        }
        cout << "\n"
             << s.size() << "\n";
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
    }
    return 0;
}