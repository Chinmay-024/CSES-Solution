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

const int INF = 1e9;
const int N = 1e5 + 5;

class Edge
{
public:
    int w, to;
    Edge(int x = INF, int y = -1)
    {
        w = x;
        to = y;
    }
    bool operator<(Edge const &other) const
    {
        return make_pair(w, to) < make_pair(other.w, other.to);
    }
};

int n;
vector<vector<Edge>> adj(N);

void prim()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<long long, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    long long weight = 0;
    vector<long long> dist(n, numeric_limits<long long>::max());
    dist[0] = 0;
    set<pair<long long, int>> q;
    q.insert({0, 0});
    vector<bool> visited(n + 1, false);
    for (int i = 0; i < n; ++i)
    {
        if (q.empty())
        {
            cout << "IMPOSSIBLE";
            exit(0);
        }
        int v = q.begin()->second;
        visited[v] = true;
        weight += q.begin()->first;
        q.erase(q.begin());

        for (auto &[cost, child] : adj[v])
        {
            if (!visited[child] && cost < dist[child])
            {
                q.erase({dist[child], child});
                dist[child] = cost;
                q.insert({cost, child});
            }
        }
    }
    cout << weight << endl;
}

// vector<int> parent, rank1;

// void make_set(int v)
// {
//     parent[v] = v;
//     rank1[v] = 0;
// }

// int find_set(int v)
// {
//     if (v == parent[v])
//         return v;
//     return parent[v] = find_set(parent[v]);
// }

// void union_sets(int a, int b)
// {
//     a = find_set(a);
//     b = find_set(b);
//     if (a != b)
//     {
//         if (rank1[a] < rank1[b])
//             swap(a, b);
//         parent[b] = a;
//         if (rank1[a] == rank1[b])
//             rank1[a]++;
//     }
// }

// struct Edge
// {
//     int u, v, weight;
//     bool operator<(Edge const &other)
//     {
//         return weight < other.weight;
//     }
// };

// int n;
// vector<Edge> edges;

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    prim();
    // int m;
    // cin >> n >> m;

    // int total_weight = 0;
    // vector<Edge> min_e(n);
    // for (int i = 0; i < m; i++)
    // {
    //     int x, y, z;
    //     cin >> x >> y >> z;
    //     edges.push_back({--x, --y, z});
    // }
    // int cost = 0;
    // vector<Edge> result;
    // parent.resize(n);
    // rank1.resize(n);
    // for (int i = 0; i < n; i++)
    //     make_set(i);

    // sort(edges.begin(), edges.end());

    // for (Edge e : edges)
    // {
    //     if (find_set(e.u) != find_set(e.v))
    //     {
    //         cout << e.u << " " << e.v << " " << e.weight << "\n";
    //         cost += e.weight;
    //         result.push_back(e);
    //         union_sets(e.u, e.v);
    //     }
    // }
    // if (result.size() == n - 1)
    //     cout << cost << endl;
    // else
    //     cout << "IMPOSSIBLE" << endl;
    return 0;
}