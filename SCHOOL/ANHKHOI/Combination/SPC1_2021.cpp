#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;
const long long maxN = 1e3 + 10;
long long dp[maxN][maxN];
long long a[maxN];
long long n, k;

int main()
{
    long long test;
    cin >> test;
    while (test--)
    {
        cin >> n >> k;
        long long totalChildren = 0;
        for (long long i = 1; i <= n; i++)
        {
            cin >> a[i];
            totalChildren += a[i];
        }
        for (long long i = 0; i <= n; i++)
        {
            for (long long j = 0; j <= k; j++)
            {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for (long long i = 0; i < n; i++)
        {
            for (long long j = 0; j <= k; j++)
            {
                long long cur = dp[i][j];
                if (j > 0)
                {
                    dp[i + 1][j] += (cur * j) % mod;
                    dp[i + 1][j] %= mod;
                }
                dp[i + 1][j + 1] += (cur * (k - j)) % mod;
                dp[i + 1][j + 1] %= mod;
            }
        }
        long long ans = 0;
        for (long long j = 1; j <= k; j++)
        {
            long long v = dp[n][j];
            v *= pow(k - j + 1, totalChildren);
            v %= mod;
            ans += v;
            ans %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}