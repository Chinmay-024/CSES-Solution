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

ll n, m;
vvi vis;
vector<string> grid;

vi dx = {1, 0, -1, 0};
vi dy = {0, 1, 0, -1};
string dir = "DRUL";

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    pii beg, end;
    rep(i, 0, n)
    {
        string s;
        cin >> s;
        rep(j, 0, s.size())
        {
            if (s[j] == 'A')
                beg = {i, j};
            if (s[j] == 'B')
                end = {i, j};
        }
        grid.push_back(s);
    }
    vis = vvi(n, vi(m, 0));
    vvi parent(n, vi(m, 0));
    int ans = 0;
    queue<pii> pq;
    pq.push(beg);
    vis[beg.ff][beg.ss] = 1;
    while (!pq.empty())
    {
        int flag = 0;
        auto x = pq.front();
        pq.pop();
        for (int i = 0; i < 4; i++)
        {
            int xnew = x.ff + dx[i];
            int ynew = x.ss + dy[i];
            if (xnew < 0 || xnew >= n || ynew < 0 || ynew >= m)
                continue;
            if (vis[xnew][ynew] || grid[xnew][ynew] == '#')
                continue;
            vis[xnew][ynew] = 1;
            parent[xnew][ynew] = i;
            pq.push({xnew, ynew});
            if (xnew == end.ff && ynew == end.ss)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
    }

    if (vis[end.ff][end.ss])
    {
        cout << "YES" << endl;
        vector<int> steps;
        while (end != beg)
        {
            int p = parent[end.ff][end.ss];
            steps.push_back(p);
            end = {end.ff - dx[p], end.ss - dy[p]};
        }
        reverse(steps.begin(), steps.end());

        cout << steps.size() << endl;
        for (char c : steps)
        {
            cout << dir[c];
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}