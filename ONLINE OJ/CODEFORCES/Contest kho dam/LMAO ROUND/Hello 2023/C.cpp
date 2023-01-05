//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define taskname "blabla"
#define endl "\n"
#define X first
#define Y second
#define Ha dethuong
using namespace std;

const int N = 2 * 1e5 + 10;

int a[N];
int f[N];

signed main(){
    int Test;
    cin >> Test;
    for (int TestCase = 1; TestCase <= Test; ++ TestCase)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            f[i] = 0;
        }

        //[m + 1; n]
        for (int i = m + 1; i <= n; i++){
            f[i] = f[i - 1] + a[i];
        }
        multiset <int> q;
        int res = 0;
        for (int i = m + 1, temp = 0; i <= n; i++){
            if (a[i] < 0){
                q.insert(a[i]);
            }
            while(q.size() and f[i] + temp < 0){
                temp -= 2 * *q.begin();
                // cout << -q.top() << endl;
                q.erase(q.begin());
                res++;

            }
            // cout << f[i] << " " << temp << endl;
        }

        // [1;m]

        for (int i = 1; i <= m; i++){
            f[i] = f[i - 1] + a[i];
        }

        q.clear();

        for (int i = m, temp = 0; i >= 1; i--){
            while(q.size() and f[i] < f[m] + temp){
                temp += 2 * *q.begin();
                // cout << q.top() << endl;
                q.erase(q.begin());
                res++;
            }
            if (a[i] > 0){
                q.insert(-a[i]);
            }
        }


        cout << res << endl;
    }
    return 0;
}