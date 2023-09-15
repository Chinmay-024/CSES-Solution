#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i, j, n) for (int i = j; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, char>
#define vii vector<pii>
#define ff first
#define ss second

const ll M = 2e6 + 20;
vector<ll> fact(M, 1);
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

int timer = 0;
ll n;
unordered_map<string, int> mp;
unordered_map<int, string> mp2;

void dfs(string s)
{
    if (s.size() == n - 1)
    {
        mp[s] = timer;
        mp2[timer++] = s;

        // cout << s << " " << timer << "\n";
        return;
    }
    dfs(s + "0");
    dfs(s + "1");
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    if (n == 1)
    {
        cout << "01";
        return 0;
    }
    vii adj[N];
    dfs("");
    int t = (1 << (n - 1));
    // cout << t;
    rep(i, 0, t)
    {
        string s = mp2[i].substr(1, n - 2);
        // cout << i << " " << s << " ? " << mp[s + "0"] << " " << '0' << "\n";

        // cout << i << " " << s << " ? " << mp[s + "1"] << " " << '1' << "\n";
        adj[i].push_back({mp[s + "0"], '0'});
        adj[i].push_back({mp[s + "1"], '1'});
    }
    string path;

    stack<pair<int, char>> st;

    st.push({0, '$'});
    while (!st.empty())
    {
        auto x = st.top();
        if (adj[x.ff].size() == 0)
        {
            if (x.ss != '$')
                path += x.ss;
            st.pop();
        }
        else
        {
            auto y = adj[x.ff].back();
            adj[x.ff].pop_back();
            st.push({y.ff, y.ss});
        }
    }
    path += mp2[0];
    cout << path;
    return 0;
}