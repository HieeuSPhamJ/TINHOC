#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 10;
int arr[maxN][maxN];
int dp[maxN][maxN][(1 << maxN)][(1 << 4)][2];

int solve(int x, int y, int maskcol, int masksub, int now)
{
    if (x == 9)
    {
        if (maskcol == 0 && masksub == 0)
            return 0;
        else
            return (1e9);
    }
    if (y == 9)
    {
        if (now != 0)
            return 1e9;
        if (x % 3 == 2 && masksub != 0)
            return (1e9);
        if (x % 3 == 2)
            masksub = 0;
        return solve(x + 1, 0, maskcol, masksub, 0);
    }
    int &ret = dp[x][y][maskcol][masksub][now];
    if (ret != -1)
        return ret;
    int choice1 = (arr[x][y] == 0) + solve(x, y + 1, maskcol ^ (1 << y), masksub ^ (1 << (y / 3)), !now);
    int choice2 = (arr[x][y] == 1) + solve(x, y + 1, maskcol, masksub, now);
    ret = min(choice1, choice2);
    return ret;
}

signed main()
{
    freopen("BISUDOKU.INP", "r", stdin);
    freopen("BISUDOKU.OUT", "w", stdout);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            char c;
            cin >> c;
            arr[i][j] = (c - '0');
        }
    }
    return cout << solve(0, 0, 0, 0, 0) << "\n", 0;
}