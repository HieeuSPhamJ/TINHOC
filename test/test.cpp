#include <bits/stdc++.h>

#define nxt "\n"

using namespace std;
const int N = 2e3 + 3;

long long n, x, y, l, k, ans = 0, q;
long long f[N][N], sum[N][N], a[N];

long long cal(int l, int r)
{
    long long res = 0;
    for (int i = l; i <= r; ++ i)
    {
        for (int j = l; j <= i; ++ j)
        {
            res = res + abs(a[i] - a[j]);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        long long currSum = 0;
        for (int j = i + 1; j <= n; j++)
        {
            currSum += abs(a[i] - a[j]);
            f[i][j] += currSum;
        }
    }
    cin >> q;
    for (int i = 1; i <= q; ++ i)
    {
        cin >> x >> y >> k;
        l = x;
        ans = 0;
        for (int j = x; j <= y; ++ j)
        {
            while (f[l][j] > k)
            {
                ++ l;
            }
            ans = ans + (j - l + 1);
        }
        cout << ans << nxt;
    }
    return 0;
}
