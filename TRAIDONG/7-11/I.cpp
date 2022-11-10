#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

struct shop
{
    int s, p, w;
};

const int N = 1e3;
shop a[200];
const int inf = 1e15;
int n, m, dp[20000];

bool cmp(shop a, shop b)
{
    return a.p < b.p;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].s >> a[i].p >> a[i].w;
    }
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= n; i++)
        dp[i] = inf;
    for (int i = 1; i <= m; i++)
    {
        for (int j = n; j >= 0; j--)
        {
            if (dp[j] != inf)
            {
                if (j + a[i].s <= n)
                {
                    dp[j + a[i].s] = min(dp[j + a[i].s], dp[j] + a[i].w + a[i].p * a[i].s);
                }
                else
                {
                    dp[n] = min(dp[n], dp[j] + a[i].w + a[i].p * (n - j));
                }
            }
        }
    }
    cout << dp[n];

    return 0;
}