#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int a[60];
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int res = 3;
        for (int t = 1; t <= n; t++){
            int i = a[t];
            int cnt = 1;
            // cout << "With: " << t << endl;
            while(t != i){
                cnt++;
                // cout << i << endl;
                i = a[i];
                if (cnt > n){
                    goto bru;
                }
            }
            res = min(res, cnt);
            bru:;
        }
        cout << res << endl;
    }
    return 0;
}