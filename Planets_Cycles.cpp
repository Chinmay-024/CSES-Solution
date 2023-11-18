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

ll n;
vi dest(N);
vi pathLength(N, 0);
vi vis(N, 0);

int step;
queue<int> path;
void dfs(int x)
{
    path.push(x);
    if (vis[x])
    {
        step += pathLength[x];
        return;
    }
    vis[x] = 1;
    step++;
    dfs(dest[x]);
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    rep(i, 0, n)
    {
        cin >> dest[i];
        dest[i]--;
    }
    rep(i, 0, n)
    {
        if (!vis[i])
        {
            step = 0;
            dfs(i);
            int dec = 1;
            while (!path.empty())
            {
                if (path.front() == path.back())
                    dec = 0;
                int x = path.front();
                path.pop();
                pathLength[x] = step;
                step -= dec;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << pathLength[i] << " ";
    }
    cout << endl;
    return 0;
}