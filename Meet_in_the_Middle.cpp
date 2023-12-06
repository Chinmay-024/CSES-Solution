#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> get_subset_sums(int l, int r, vector<ll> a)
{
    int len = r - l + 1;
    vector<ll> res;

    for (int i = 0; i < (1 << len); i++)
    {
        ll sum = 0;
        for (int j = 0; j < len; j++)
        {
            if (i & (1 << j))
            {
                sum += a[l + j];
            }
        }
        res.push_back(sum);
    }

    return res;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<ll> left = get_subset_sums(0, n / 2 - 1, a);
    vector<ll> right = get_subset_sums(n / 2, n - 1, a);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    ll ans = 0;
    for (ll i : left)
    {
        auto low_iterator = lower_bound(right.begin(), right.end(), x - i);
        auto high_iterator = upper_bound(right.begin(), right.end(), x - i);
        int start_index = low_iterator - right.begin();
        int end_index = high_iterator - right.begin();
        ans += end_index - start_index;
    }

    cout << ans << endl;
}