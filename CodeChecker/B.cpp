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
const int N = 1e3 + 9;

int n, ans;
int a[N], tree[4 * N], init[N], dp[N];

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

int get(int index, int l, int r, int x, int y)
{
    if (x > r || y < l)
    {
        return 0;
    }
    if (x <= l && y >= r)
    {
        return tree[index];
    }
    int mid = (l + r) >> 1;
    int curr1 = get(index << 1, l, mid, x, y);
    int curr2 = get(index << 1 | 1, mid + 1, r, x, y);
    return curr1 + curr2;
}

void update(int index, int l, int r, int pos, int val)
{   
    // cout << index << ' ' << l << ' ' << r << ' ' << pos << ' ' << val << endl;
    if (pos < l || pos > r)
    {
        return;
    }
    if (l == r)
    {
        tree[index] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(index << 1, l, mid, pos, val);
    update(index << 1 | 1, mid + 1, r, pos, val);
    tree[index] = tree[index << 1] + tree[index << 1 | 1];
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
        int pos = get(1, 1, n, 1, a[i] - 1) + 1;
        update(1, 1, n, a[i], 1);
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
        update(1, 1, n, a[i], 0);
    }
    return res;
}

signed main()
{
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    // freopen (taskname".inp", "r", stdin);
    // freopen (taskname".out", "w", stdout);

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