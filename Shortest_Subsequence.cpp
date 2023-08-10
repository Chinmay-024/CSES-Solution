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

string s;
int a[4][4];
unordered_map<char, int> mp;

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int n = s.size();
    mp['A'] = 0;
    mp['T'] = 1;
    mp['G'] = 2;
    mp['C'] = 3;
    int A = 0, T = 0, G = 0, C = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int q = mp[s[i]];
        switch (q)
        {
        case 0:
            A++;
            a[0][0] = A;
            a[0][1] = T;
            a[0][2] = G;
            a[0][3] = C;
            break;
        case 1:
            T++;
            a[1][0] = A;
            a[1][1] = T;
            a[1][2] = G;
            a[1][3] = C;
            break;
        case 2:
            G++;
            a[2][0] = A;
            a[2][1] = T;
            a[2][2] = G;
            a[2][3] = C;
            break;
        case 3:
            C++;
            a[3][0] = A;
            a[3][1] = T;
            a[3][2] = G;
            a[3][3] = C;
            break;
        }
    }
    int ans = INT_MAX;
    int x = -1;
    int y = -1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] < ans)
            {
                ans = a[i][j];
                x = i;
                y = j;
            }
        }
    }
    if (x == 0)
        cout << 'A';
    if (x == 1)
        cout << 'T';
    if (x == 2)
        cout << 'G';
    if (x == 3)
        cout << 'C';
    ans++;
    while (ans > 0)
    {
        if (y == 0)
            cout << 'A';
        if (y == 1)
            cout << 'T';
        if (y == 2)
            cout << 'G';
        if (y == 3)
            cout << 'C';
        ans--;
    }

    return 0;
}