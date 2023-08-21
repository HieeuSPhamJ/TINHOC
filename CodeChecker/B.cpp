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
    int a[1000];
    int n, test;
    cin >> n >> test;
    memset(a,0,sizeof(a));
    while(test--){
        int t;
        cin >> t;
        if (t == 1){
            int l, r, x;
            cin >> l >> r >> x;
            for (int i = l; i <= r; i++){
                a[i] = a[i] xor x;
            }
        }
        else{
            int l, r;
            int res = 0;
            cin >> l >> r;
            for (int i = l; i <= r; i++){
                res = res xor a[i];
            }
            cout << res << endl;
            memset(a,0,sizeof(a));
        }
    }
    return 0;
}