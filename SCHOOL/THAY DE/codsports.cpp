#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
// #define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
int t[maxN];
int n;

bool cmp(ii a, ii b)
{
    return a.fi > b.fi;
}

bool check(int time)
{
    // cout << "==Time==" << time << endl;
    vector<ii> lists;
    for (int i = 1; i <= n; i++)
    {
        int step = t[i] / time;
        int left = a[i] - step;
        if (left <= 0)
        {
            left = 1;
        }
        int right = a[i] + step;
        if (right > n)
        {
            right = n;
        }
        // cout << left << ' ' << right << " " << step << " " << t[i] << " " << time << endl;

        lists.push_back({left, right});
    }
    sort(all(lists), cmp);
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++)
    {
        while (lists.size() and lists.back().fi <= i)
        {
            q.push(lists.back().se);
            lists.pop_back();
        }
        if (q.empty())
        {
            return 0;
        }
        q.pop();
        while (q.size() and q.top() <= i)
        {
            q.pop();
        }
    }
    return 1;
}

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    int left = 1;
    int right = 1e8;
    int ans = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (check(mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    // cout << ans << endl;
    int test;
    cin >> test;
    while (test--)
    {
        int x;
        cin >> x;
        if (x <= ans)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
        cout << " ";
    }
}
