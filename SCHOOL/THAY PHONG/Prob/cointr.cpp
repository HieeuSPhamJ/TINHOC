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
    int n;
    cin >> n;
    int l = 1;
    int r = min((int)1e9,n);
    int res = 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if (mid * (mid + 1) / 2 <= n){
            res = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << res << endl;
    return 0;
}