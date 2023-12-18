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

const int mod = 1e9 + 7;

int a[1000];

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    while(test--){
        int t,l,r;
        cin >> t >> l >> r;
        if (t == 0){
            for (int i = l; i <= r; i++){
                a[i]++;
            }
        }
        else{
            int res = 0;
            for (int i = l; i <= r; i++){
                (res += a[i] * a[i] * a[i]) %= mod;
            }
            cout << res << endl;
        }
    }
    return 0;
}