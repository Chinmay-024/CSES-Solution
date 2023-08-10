#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i, j, n) for (int i = j; i < n; i++)
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second

const ll M = 2e6 + 20;
vector<ll> fact(M, 1);
const int N = 1e5 + 7;
const ll MOD = 1e9 + 7;

string s;
int n, k;
vi dp(5002, 0);
class node
{
public:
    bool end;
    node *next[26];
    node()
    {
        end = false;
        rep(i, 0, 26)
        {
            next[i] = NULL;
        }
    }
};
ll ans = 0;
class Trie
{
public:
    node *t;
    Trie()
    {
        t = new node();
    }
    void add(string s)
    {
        int idx = 0;
        node *temp = t;
        int sz = s.size();
        while (idx < sz)
        {
            if (temp->next[s[idx] - 'a'] == NULL)
                temp->next[s[idx] - 'a'] = new node();
            temp = temp->next[s[idx] - 'a'];
            idx++;
        }
        temp->end = true;
    }
    ll search(int x)
    {
        ll q = 0;
        node *temp = t;
        for (int i = x; i < s.size(); i++)
        {
            if (temp->next[s[i] - 'a'] == NULL)
                return q;
            else
            {
                temp = temp->next[s[i] - 'a'];
                if (temp->end)
                    q += (dp[i + 1] % MOD);
                q %= MOD;
            }
        }
        return q;
    }
};

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> k;
    n = s.size();
    Trie *t = new Trie();
    rep(i, 0, k)
    {
        string q;
        cin >> q;
        t->add(q);
    }
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = t->search(i);
        // cout << i << " " << dp[i] << "\n";
    }
    cout << dp[0];
    return 0;
}