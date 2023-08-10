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
    if (n == 1)
    {
        cout << 1;
    }
    else if (n == 2)
    {
        cout << "NO SOLUTION";
    }
    else if (n == 3)
    {
        cout << "NO SOLUTION";
    }
    else if (n == 4)
    {
        cout << 2 << " " << 4 << " " << 1 << " " << 3;
    }
    else
    {
        if (n % 2 == 0)
        {
            int m = n;
            while (m > 0)
            {
                cout << m << " ";
                m -= 2;
            }
            n--;
            while (n > 0)
            {
                cout << n << " ";
                n -= 2;
            }
        }
        else
        {
            int m = n - 1;
            while (m > 0)
            {
                cout << m << " ";
                m -= 2;
            }

            while (n > 0)
            {
                cout << n << " ";
                n -= 2;
            }
        }
    }

    return 0;
}