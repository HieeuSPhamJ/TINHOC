#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define MOD 2023
#define INF 1e18
#define fi first
#define se second
#define endl "\n"
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define sz(a) ((int)(a).size())
#define pi 3.14159265359
#define TASKNAME ""
template <typename T>
bool maximize(T &res, const T &val)
{
    if (res < val)
    {
        res = val;
        return true;
    };
    return false;
}
template <typename T>
bool minimize(T &res, const T &val)
{
    if (res > val)
    {
        res = val;
        return true;
    };
    return false;
}
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
const int MAXN = 110;
int a[MAXN], n, dp[MAXN][MAXN][MAXN];
int dir[MAXN];
bool gd[MAXN][MAXN];

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    else
        return gcd(b % a, a);
}
main()
{
    fast;
    // freopen(TASKNAME".inp","r",stdin);
    // freopen(TASKNAME".out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dir[a[i]] = i;
        dp[i][i][1] = 1;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
                gd[i][j] = false;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (gcd(a[i], a[j]) == 1)
                gd[i][j] = true;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n + 1; k++)
            {
                for (int t = 1; t <= n; t++)
                {
                    if (gd[j][t])
                    {
                        dp[i][t][k] = (dp[i][t][k] + dp[i][j][k - 1]) % MOD;
                    }
                }
            }
        }
    }
    int test;
    cin >> test;
    int l, r, k;
    while (cin >> l >> r >> k)
    {
        l = dir[l];
        r = dir[r];
        k++;
        cout << dp[l][r][k] << endl;
    }
}