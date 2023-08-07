#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;
const int maxN = 2000;

int n, k;
int a[maxN];

int check(int x)
{
    for (int i = 1; i <= n; ++ i)
    {
        if (a[i] >= x)
        {
            return 1;
        }
    }
    int cnt;
    for (int i = 1; i < n; ++ i)
    {
        cnt = 0;
        for (int j = i; j <= n; ++ j)
        {
            if (j == n)
            {
                if (a[n] >= x - (n - i))
                {
                    return 1;
                }
                cnt = k + 1;
                break;  
            }   
            if (a[j] >= x - (j - i))
            {
                // cout << "**" << i << ' ' << j << endl;
                return 1;
            }
            cnt = cnt + (x - (j - i)) - a[j];
            if (cnt > k)
            {
                break;
            }
        }
        if (cnt > k)
        {
            continue;
        }
        else
        {
            // cout << "***" << i << ' ' << cnt << endl;
            return 1;
        }
    }
    return 0;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Test;
    cin >> Test;
    for (int TestCase = 1; TestCase <= Test; ++ TestCase)
    {
        cin >> n >> k;
        int l = -1;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            l = max(l, a[i]);
        }
        int r = 1e18, mid, res = l;
        while(l <= r)
        {
            mid = (l + r) >> 1;
            if (check(mid))
            {
                l = mid + 1;
                res = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        // cout << check(5) << endl;
        cout << res << endl;
    }
    return 0;
}