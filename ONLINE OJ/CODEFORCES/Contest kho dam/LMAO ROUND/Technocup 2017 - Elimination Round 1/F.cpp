#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

priority_queue<int> q;
int a[800];
int sum[800];
int c;
int n, m;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i >= 1; i--)
    {
        if (a[i] < 0)
            q.push(a[i]);
        else
        {
            while (!q.empty() && a[i] >= 0)
            {
                a[i] += q.top();
                q.pop();
            }
            if (a[i] < 0)
                q.push(a[i]);
        }
    }
    while (!q.empty())
    {
        sum[++c] = q.top();
        q.pop();
    }
    for (int i = 1; i <= c; i++)
        sum[i] += sum[i - 1];
    for (int i = 1; i <= c; i++)
        sum[i] = -sum[i];
    int x;
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        cout << c - (upper_bound(sum + 1, sum + 1 + c, x) - sum) + 1 << endl;
    }
    return 0;
}