#include <bits/stdc++.h>

#define emotion "Chu he thoi dai"
#define taskname "blabla"
#define endl "\n"
#define X first
#define Y second
#define int long long
#define FangIo_oI top1

using namespace std;
typedef pair <long long, int> ii;
const long long oo = 1e18 + 6;
const long long mod = 1e9 + 7; // 998244353
const int N = 4e4 + 6;

int n, n1;
vector <int> qeri;

signed main()
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
        cin >> n;
        n1 = n;
        int bit = 0;
        qeri.clear();
        qeri.push_back(n);
        while (n1 > 1)
        {
            // cout << n1 << endl;
            if (n1 & 1)
            {
                // cout << bit << endl;
                qeri.push_back(n - (1 << bit));
                n = n - (1 << bit);
            }
            ++ bit;
            n1 = n1 >> 1;
        }
        n1 = (n1 << bit);
        while (n1 != 0)
        {
            qeri.push_back(n1 / 2);
            n1 = n1 >> 1;
        }
        qeri.pop_back();
        cout << qeri.size() << endl;
        for (int x : qeri)
        {
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}