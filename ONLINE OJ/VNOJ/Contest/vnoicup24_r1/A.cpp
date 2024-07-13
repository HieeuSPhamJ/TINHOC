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
        int res1 = 0;
        int res2 = 0;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            if (x == 1){
                res1++;
            }
            else if (x == 2){
                res2++;
            }
            else{
                res1 += (x - 2);
                res2 += 1;
            }
        }
        cout << res1 / 2 + res2 / 2 << endl;
    }
    return 0;
}