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
        int n;
        cin >> n;
        int l = 1;
        int r = 4e9;
        int res = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            if (mid * (mid - 1) / 2 <= n){
                l = mid + 1;
                res = n - mid * (mid - 1) / 2 + mid;
            }
            else{
                r = mid - 1;
            }
        }
        cout << res << endl;
    }
    return 0;
}