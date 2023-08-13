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

class SuffixArray
{
public:
    int MAX_N = (int)2e6 + 2;
    int n = -1;
    string s;
    vector<int> RA;
    vector<int> SA;
    vector<int> tempRA;
    vector<int> tempSA;

    int lcp;

    void countingSort(int k)
    {                              // O(n)
        int i, maxi = max(130, n); // up to 255 ASCII chars or length of n
        int sum = 0;
        int *c = new int[MAX_N];
        memset(c, 0, sizeof(c)); // clear frequency table
        for (int i = 0; i < n; i++)
            c[i + k < n ? RA[i + k] : 0]++; // count the frequency integer rank

        for (i = 0; i < maxi; i++)
        {
            int t = c[i];
            c[i] = sum;
            sum += t;
        }
        for (i = 0; i < n; i++) // shuffle the suffix array if necessary
            tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];

        for (i = 0; i < n; i++) // update the suffix array SA
            SA[i] = tempSA[i];
    }
    SuffixArray(string x)
    {
        RA = vector<int>(MAX_N, 0);
        SA = vector<int>(MAX_N, 0);
        tempRA = vector<int>(MAX_N, 0);
        tempSA = vector<int>(MAX_N, 0);
        s = x;
        // s += '$';
        n = s.length();
        for (int i = 0; i < n; i++)
            RA[i] = s[i];
        for (int i = 0; i < n; i++)
            SA[i] = i;

        for (int k = 1; k < n; k *= 2)
        {
            countingSort(k);
            countingSort(0);

            int r = 0;
            tempRA[SA[0]] = r;          // re-ranking; start from rank r = 0
            for (int i = 1; i < n; i++) // compare adjacent suffixes if same pair => s: otherwise, increase r
            {
                tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
            }

            for (int i = 0; i < n; i++)
            {
                RA[i] = tempRA[i];
            } // update the rank array I
            if (RA[SA[n - 1]] == n - 1l)
                break; // nice optimization trick
        }
    }
};

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int q = s.size();
    s += s;
    SuffixArray *ab = new SuffixArray(s);
    int i = 0;
    for (int x : ab->SA)
    {
        if (i < ab->n)
        {
            if (x < q)
            {
                cout << ab->s.substr(x, q) << "\n";
                return 0;
            }
            i++;
        }
    }
    return 0;
}