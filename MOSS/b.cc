//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define taskname "blabla"
#define endl "\n"
#define X first
#define Y second
#define int long long
#define Ha dethuong

using namespace std;
typedef pair <int, int> ii;
const int oo = 1e9 + 3;
const long long mod = 1e9 + 7; // 998244353
const int N = 2e5 + 3;

int n, x, maxx, minn;
vector <int> a;
vector <int> v;

signed main()
{
//   freopen (taskname".inp", "r", stdin);
//   freopen (taskname".out", "w", stdout);

    freopen ("test.inp", "r", stdin);
    freopen ("test.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Test;
    cin >> Test;
    for (int TestCase = 1; TestCase <= Test; ++ TestCase)
    {
        cin >> n;
        if (n == 2)
        {
            int x, y;
            cin >> x >> y;
            cout << x << endl;
            continue;
        }
        a.clear();
        a.push_back(-1);
        v.clear();
        for (int i = 1; i <= n; ++ i)
        {
            cin >> x;
            if (x != a[a.size() - 1])
            {
                a.push_back(x);
            }
        }
        maxx = 0;
        minn = oo;
        n = a.size() - 1;
        a.push_back(a[n - 1]);
        a[0] = a[2];
//        cout << a[0] << ' ';
        for (int i = 1; i <= n; ++ i)
        {
//            cout << a[i] << ' ';
            if ((a[i] - a[i - 1]) * (a[i] - a[i + 1]) > 0)
            {
//                cout << i << endl;
                v.push_back(i);
            }
        }
//        cout << a[n + 1] << endl;
//        cout << endl;
//        for (int i : v)
//        {
//            cout << i << ' ';
//        }
//        cout << endl;
        int l, r;
        for (int i = 0; i < v.size() - 1; ++ i)
        {
            l = v[i], r = v[i + 1];
            if (a[r] > a[l])
            {
                minn = min(minn, (a[l] + a[l + 1]) / 2);
            }
            else
            {
                maxx = max(maxx, (a[l] + a[l + 1] + 1) / 2);
            }
        }
        if (maxx <= minn)
        {
            cout << maxx << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}

