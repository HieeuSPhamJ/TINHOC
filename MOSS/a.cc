#include <bits/stdc++.h>

#define taskname "blabla"
#define endl "\n"
#define X first
#define Y second
#define int long long
#define FangIo_oI top1

using namespace std;
typedef pair <long long, int> ii;
const long long oo = 1e18 + 9;
const long long mod = 1e9 + 7; // 998244353
const int N = 5e3 + 9;

int n, ans;
int a[N], tree[4 * N], init[N], dp[N];
int BIT[N];

void compress()
{
    vector <int> curr;
    curr.push_back(0);
    for (int i = 1; i <= n; ++ i)
    {
        curr.push_back(a[i]);
    }
    sort(curr.begin(), curr.end());
    for (int i = 1; i <= n; ++ i)
    {
        a[i] = lower_bound(curr.begin(), curr.end(), a[i]) - curr.begin();
    }
}

void update(int id, int val) {
    while (id <= n) {
        BIT[id] += val;
        id += id & -id;
    }
}

int get(int id) {
    int ans = 0;
    while (id > 0) {
        ans += BIT[id];
        id -= id & -id;
    }
    return ans;
}

int start(int key)
{
    int res = 0, lim = 0;

    for (int i = 0; i <= n; ++ i)
    {
        init[i] = dp[i] = 0;
    }
    for (int i = key; i <= n; ++ i)
    {
        int pos = get(a[i] - 1) + 1;
        update(a[i], 1);
        while (pos <= init[lim])
        {
            init[lim] = dp[lim] = 0;
            -- lim;
        }
        ++ lim;
        init[lim] = i - key + 1;
        dp[lim] = dp[lim - 1] + init[lim] - (init[lim - 1] + 1);
        res = res + dp[lim];
    }
    for (int i = key; i <= n; ++ i)
    {
        update(a[i], -1);
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Test;
    cin >> Test;
    for (int TestCase = 1; TestCase <= Test; ++ TestCase)
    {
        cin >> n;
        for (int i = 1; i <= n; ++ i)
        {
            cin >> a[i];
        }
        compress();
        // cout << start(1) << endl;
        ans = 0;
        for (int i = 1; i <= n; ++ i)
        {
            ans = ans + start(i);
            // cout << start(i) << ' ';
        }
        // cout << endl;
        cout << ans << endl;
    }

    return 0;
}