#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, x;
        ii ans;
        vector <int> a;
        vector <int> v;
        cin >> n;
        if (n == 2)
        {
            int x, y;
            cin >> x >> y;
            cout << x << endl;
            continue;
        }
        a.push_back(-1);
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            if (x != a[a.size() - 1])
            {
                a.push_back(x);
            }
        }
        ans.se = 0;
        ans.fi = 1e18;
        n = a.size() - 1;
        a.push_back(a[n - 1]);
other

        a[0] = a[2];
        for (int i = 1; i <= n; i++)
        {
            if ((a[i] - a[i - 1]) * (a[i] - a[i + 1]) > 0)
            {
                v.push_back(i);
            }
        }
other

        int l, r;
        for (int i = 0; i < v.size() - 1; i++)
        {
            l = v[i], r = v[i + 1];
            if (a[r] > a[l])
            {
                ans.fi = min(ans.fi, (a[l] + a[l + 1]) / 2);
            }
            else
            {
other

                ans.se = max(ans.se, (a[l] + a[l + 1] + 1) / 2);
            }
        }
        if (ans.se <= ans.fi){
            cout << ans.se << endl;
            continue;
        }
        cout << -1 << endl;
    
    }
    return 0;
}


/*
+  <= -tbm(2min)
-  >= -tbm(2max)

5 3 4 5
1 1 0 1

2

10 5 4 3 2 1
2 3 4  5 6 

*/