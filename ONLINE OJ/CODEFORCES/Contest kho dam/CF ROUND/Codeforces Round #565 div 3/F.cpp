#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 2 * 1e5 + 10;

vector<int> a[maxN][5];
int dp[maxN][12];
int dp2[4][4];

signed main()
{
    // freopen("input.INP", "r", stdin);
    // freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < maxN; i++)
        for (int j = 0; j < 10; j++)
            dp[i][j] = -1e18;
    dp[0][0] = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int c, d;
            cin >> c >> d;
            a[i][c].push_back(d);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            int s = (j == 1 ? 3 : 1);
            sort(a[i][j].begin(), a[i][j].end());
            reverse(a[i][j].begin(), a[i][j].end());
            while (a[i][j].size() > s)
                a[i][j].pop_back();
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 2; k++)
                dp2[j][k] = -1e18;
        dp2[0][0] = 0;
        vector<pair<int, int>> cur;
        for (int j = 1; j <= 3; j++)
            for (auto x : a[i][j])
                cur.push_back(make_pair(j, x));
        sort(cur.begin(), cur.end());
        do
        {
            int mana = 3;
            int score = 0;
            int mx = 0;
            int cnt = 0;
            for (auto x : cur)
            {
                cnt++;
                if (mana < x.first)
                    break;
                mana -= x.first;
                mx = max(mx, (int)(x.second));
                score += x.second;
                dp2[cnt][0] = max(dp2[cnt][0], score);
                dp2[cnt][1] = max(dp2[cnt][1], score + mx);
            }
        } while (next_permutation(cur.begin(), cur.end()));
        for (int j = 0; j < 10; j++)
            for (int k = 0; k <= 3; k++)
            {
                int nxt = (j + k) % 10;
                int f = (j + k >= 10 ? 1 : 0);
                dp[i + 1][nxt] = max(dp[i + 1][nxt], dp[i][j] + dp2[k][f]);
            }
    }
    int ans = 0;
    for (int i = 0; i <= 9; i++)
        ans = max(ans, dp[n][i]);
    cout << ans;
    return 0;
}