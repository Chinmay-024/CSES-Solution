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
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

ll n, q;

int parent[N][31];

int jump(int a, int b)
{
    for (int i = 0; i < 31; i++)
    {
        if (b & (1 << i))
        {
            a = parent[a][i];
        }
    }
    return a;
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        parent[i + 1][0] = x;
    }
    for (int i = 1; i < 31; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
    while (q)
    {
        q--;
        int a, b;
        cin >> a >> b;
        cout << jump(a, b) << "\n";
    }
    return 0;
}