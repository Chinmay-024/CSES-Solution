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

int main()
{
    ll n, m;
    cin >> n >> m;
    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    ll s = 0, c = 0;
    unordered_map<int, int> mp;
    rep(i, 0, n)
    {
        if (mp.count(a[i] - 1) == 0)
            c++;
        mp[a[i]] = i;
    }
    mp[0] = -1;
    // cout << c << "\n";

    rep(j, 0, m)
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        int p = a[x];
        int q = a[y];
        set<pii> s;
        s.insert({p - 1, p});
        s.insert({p, p + 1});
        s.insert({q - 1, q});
        s.insert({q, q + 1});
        unordered_map<int, int> mp2;
        mp2[a[x]] = y;
        mp2[a[y]] = x;
        for (auto j : s)
        {
            int f = j.ff;
            int s = j.ss;
            int ox, oy, nx, ny;
            ox = mp[f];
            oy = mp[s];
            nx = mp2.count(f) ? mp2[f] : mp[f];
            ny = mp2.count(s) ? mp2[s] : mp[s];
            if (ox < oy && nx > ny)
                c++;
            if (ox > oy && nx < ny)
                c--;
        }
        for (auto j : mp2)
        {
            mp[a[x]] = y;
            mp[a[y]] = x;
        }
        swap(a[x], a[y]);
        cout << c << "\n";
    }
    return 0;
}