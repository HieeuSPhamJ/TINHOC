#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;


int cal(int l1, int r1, int l2, int r2){
    int res = 0;
    int l = max(l1,l2);
    int r = min(r1,r2);
    int n = r - l + 1;
    if (l <= r){
        res = n * (n - 1) / 2;
        // cout << "m " << res << endl;
    }
    if (n * (l - l2) > 0){
        res += n * (l - l2);
        // cout << "l " << n * (l - l2) << endl;
    }
    res += (r1 - max(r,l1 - 1)) * (r2 - l2 + 1);
    // cout << "r " << (r1 - max(r,l1 - 1)) * (r2 - l2 + 1) << endl;
    return res;
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int res = 0;
    for (int i = a; i <= b; i++){
        // cout << "With: " << i << endl;
        // cout << c - i << " " << d - i << endl;
        int t = cal(b,c,c - i,d - i);
        res += t;
    }
    cout << res << endl;
    return 0;
}