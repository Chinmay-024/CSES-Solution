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

int adv(int x, int dis)
{
    for (int i = 30; i >= 0; i--)
    {
        if (dis & (1 << i))
            x = parent[x][i];
    }
    return x;
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    vector<int> next(n + 1);
    vector<int> before[n + 1];

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        next[i + 1] = x;
        parent[i + 1][0] = x;
        before[x].push_back(i + 1);
    }
    vector<map<int, int>> cycles;
    vector<int> cycleIdx(n + 1, -2);

    for (int i = 1; i <= n; i++)
    {
        int at = i;
        vector<int> path;
        while (cycleIdx[at] == -2)
        {
            path.push_back(at);
            cycleIdx[at] = -3;
            at = next[at];
        }
        bool isCycle = false;
        int j = i;
        map<int, int> cycle;
        for (auto k : path)
        {
            if (isCycle || k == at)
                isCycle = true;
            if (isCycle)
                cycle[k] = cycle.size();
            cycleIdx[k] = isCycle ? cycles.size() : -1;
            // cout << k << " " << cycle.size() << " ";
        }
        cout << "\n";
        if (isCycle)
            cycles.push_back(cycle);
    }

    // cout << cycles[0].size() << "!!";
    // for (int i = 1; i <= n; i++)
    //     cout << cycles[0][i] << " ";

    for (int i = 1; i < 31; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
    vector<int> cycleDis(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        queue<int> q;
        if (cycleIdx[i] == -1 && cycleIdx[next[i]] != -1)
        {
            q.push(i);
            cycleDis[i] = 1;
            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                for (auto j : before[x])
                {
                    q.push(j);
                    cycleDis[j] = cycleDis[x] + 1;
                }
            }
        }
    }
    while (q)
    {
        // cout << "->";
        // for (int i = 0; i < n; i++)
        //     cout << cycles[i].size() << " ";
        // cout << "\n";
        q--;
        int a, b;
        cin >> a >> b;
        if (cycleIdx[a] != -1 && cycleIdx[b] != -1)
        {
            if (cycleIdx[a] == cycleIdx[b])
            {
                int x1 = cycles[cycleIdx[a]][a];
                int y1 = cycles[cycleIdx[b]][b];
                if (y1 >= x1)
                    cout << y1 - x1 << "\n";
                else
                    cout << y1 - x1 + cycles[cycleIdx[b]].size() << "\n";
            }
            else
                cout << "-1\n";
        }
        else if (cycleIdx[a] == -1 && cycleIdx[b] != -1)
        {
            int dis = cycleDis[a];
            int x = adv(a, dis);
            if (cycleIdx[x] == cycleIdx[b])
            {
                int x1 = cycles[cycleIdx[x]][x];
                int y1 = cycles[cycleIdx[b]][b];
                if (y1 >= x1)
                    cout << y1 - x1 + dis << "\n";
                else
                    cout << y1 - x1 + dis + cycles[cycleIdx[b]].size() << "\n";
            }
            else
                cout << "-1\n";
        }
        else if (cycleIdx[a] == -1 && cycleIdx[b] == -1)
        {
            if (cycleIdx[adv(a, cycleDis[a])] == cycleIdx[adv(b, cycleDis[b])] && cycleDis[a] >= cycleDis[b])
            {
                int dis = cycleDis[a] - cycleDis[b];
                if (adv(a, dis) == b)
                    cout << dis << "\n";
                else
                    cout << "-1\n";
            }
            else
                cout << "-1\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}