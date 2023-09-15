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

set<string> s1;

void generate(string q, string s)
{
    if (s == "")
        s1.insert(q);
    rep(i, 0, s.size())
    {
        generate(q + s[i], s.substr(0, i) + s.substr(i + 1));
    }
}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    string q = "";
    generate(q, s);
    cout << s1.size() << endl;
    for (auto i : s1)
        cout << i << "\n";
    return 0;
}