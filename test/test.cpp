#include <bits/stdc++.h>

#define taskname "blabla"
#define endl "\n"
#define fi first
#define se second
#define Ha dethuong

using namespace std;
typedef pair <int, int> ii;
const long long oo = 1e18 + 3;
const long long mod = 1e9 + 7; // 998244353
const int N = 1e6 + 3;

int a[N];
int ans1[N], ans2[N];
int check[N];
int main()
{
//   freopen (taskname".inp", "r", stdin);
//   freopen (taskname".out", "w", stdout);

    // freopen ("test.inp", "r", stdin);
    // freopen ("test.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Test;
    cin >> Test;
    for (int TestCase = 1; TestCase <= Test; ++ TestCase)
    {
        int n;
        cin >> n;
        int ok = 1;
        set <int> se1,se2;
        for (int i = 1; i <= n; ++ i)
        {
            se1.insert(i);
            se2.insert(i);
            ans1[i] = ans2[i] = 0;
            check[i] = 0;
        }
        multiset <ii> ms;
        for (int i = 1; i <= n; ++ i)
        {
            cin >> a[i];
            ms.insert(make_pair(a[i],i));
            if (check[a[i]] == 0)
            {
                se1.erase(a[i]);                
                ans1[i] = a[i];
                check[a[i]] = 1;
                continue;
            }
            if (check[a[i]] == 1)
            {
                se2.erase(a[i]);
                ans2[i] = a[i];
                check[a[i]] = 3;
                continue;
            }
            ok = 0;
        
        }
        while(ms.size())
        {
            auto i = *ms.begin();
            if (ans1[i.se] == 0)
            {
                if (*se1.begin() <= i.fi)
                {
                    ans1[i.se] = *se1.begin();
                }
                else
                {
                    ok = 0;
                }
                se1.erase(se1.begin());
            }
            else
            {
                if (*se2.begin() <= i.fi)
                {
                    ans2[i.se] = *se2.begin();
                }
                else
                {
                    ok = 0;
                }
                se2.erase(se2.begin());
            }
            ms.erase(ms.begin());
        }
        if (ok == 0)
        {
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            for (int i = 1; i <= n; ++ i)
            {
                cout << ans1[i] << " ";
            }
            cout << endl;
            for (int i = 1; i <= n; ++ i)
            {
                cout << ans2[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}