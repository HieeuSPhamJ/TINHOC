#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int m, k, a1,ak;
        cin >> m >> k >> a1 >> ak;
        int res = 0;
        if (m % k >= a1){
            res += m % k - a1;
            a1 = 0;
        }
        else{
            a1 -= m % k;
        }
        int t = m / k - (ak + a1 / k);
        if (t <= 0){
            t = 0;
        }
        res += t;
        cout << res << endl;
    }
    return 0;
}