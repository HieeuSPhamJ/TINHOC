#include <bits/stdc++.h>

#define emotion "Chu he thoi dai"
#define taskname "blabla"
#define endl "\n"
#define X first
#define Y second
#define FangIo_oI top1

using namespace std;
typedef pair <long long, int> ii;
const long long oo = 1e18 + 6;
const long long mod = 1e9 + 7; // 998244353
const int N = 1e6 + 6;

int n, m, d, ans, id, cnt;
int a[N], pre[N], suf[N];

int main()
{
    // freopen (taskname".inp", "r", stdin);
    // freopen (taskname".out", "w", stdout);

    freopen ("test.inp", "r", stdin);
    freopen ("test.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Test;
    cin >> Test;
    for (int TestCase = 1; TestCase <= Test; ++ TestCase)
    {
        cin >> n >> m >> d;
        for (int i = 1; i <= m; ++ i)
        {
            cin >> a[i];
        }
        a[0] = 1;
        pre[0] = 1;
        a[m + 1] = n + 1;
        if (a[1] == 1)
        {
            pre[1] = 1;
        }
        else
        {
            pre[1] = 2 + (a[1] - 2) / d;
        }
        for (int i = 2; i <= m + 1; ++ i)
        {
            pre[i] = pre[i - 1] + 1 + (a[i] - a[i - 1] - 1) / d;
        }
        -- pre[m + 1];
        suf[m + 1] = 0;
        for (int i = m; i >= 1; -- i)
        {
            suf[i] = suf[i + 1] + 1 + (a[i + 1] - a[i] - 1) / d;
        }
        int curr;
        ans = n + 1;
        cnt = 0;
        for (int i = 1; i <= m; ++ i)
        {
            curr = pre[i - 1] + suf[i + 1];
            curr = curr + (a[i + 1] - a[i - 1] - 1) / d;
            // cout << i << endl;
            // cout << pre[i - 1] << ' ' << suf[i + 1] << endl;
            // cout << (a[i + 1] - a[i - 1] - 1) / d
            if (curr < ans)
            {
                ans = curr;
                cnt = 1;
            }
            else if (curr == ans)
            {
                ++ cnt;
            }
            // cout << curr << ' ' << i << endl;
        }
        cout << ans << ' ' << cnt << endl;
    }

    return 0;
}
