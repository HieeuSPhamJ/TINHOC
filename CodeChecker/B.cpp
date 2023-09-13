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
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int res = 0;
    for (int i = a; i <= b; i++){
        int t = 0;
        for (int j = b; j <= c; j++){
            for (int k = c; k <= d; k++){
                if (k < i + j){
                    t++;
                    res++;
                }
            }
        }
        // cout << i << ": " << t << endl;
    }
    cout << res << endl;
    return 0;
}