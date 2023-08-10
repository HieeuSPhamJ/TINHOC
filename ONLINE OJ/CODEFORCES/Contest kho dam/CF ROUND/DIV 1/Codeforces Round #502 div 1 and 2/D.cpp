#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int conv(string s)
{
    int a = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            a += (1 << i);
        }
    }
    return a;
}

signed main()
{
    // freopen("input.INP", "r", stdin);
    // freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n1, m, q;
    cin >> n1 >> m >> q;
    int w[n1];
    for (int i = 0; i < n1; i++)
    {
        cin >> w[i];
    }
    int n = pow(2, n1);
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    int wu[5000];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            if (i & (1 << j))
            {
                wu[i] += w[j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            dp[i][j] = wu[(i ^ (~j)) & (n - 1)];
        }
    }
    int m1[5000] = {0};
    string s;
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        m1[conv(s)]++;
    }
    int a[n][101];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] <= 100)
            {
                a[i][dp[i][j]] += m1[j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            a[i][j] += a[i][j - 1];
        }
    }

    int k;
    for (int i = 0; i < q; i++)
    {
        cin >> s;
        cin >> k;
        cout << a[conv(s)][k] << endl;
    }

    return 0;
}