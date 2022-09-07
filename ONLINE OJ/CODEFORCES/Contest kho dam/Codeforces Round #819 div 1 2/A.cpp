#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
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
        vector <int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int res = 0;
        for (int i = 1; i < n; i++){
            int mn = 1e18;
            for (int j = 0; j <= i; j++){
                mn = min(mn, a[j]);
            }
            int mx = 0;
            for (int j = 0; j <= i; j++){
                mx = max(mx, a[j]);
            }
            res = max({res, mx - a[0], a[n - 1] - mn, a[i - 1] - a[i]});
        }
        cout << res << endl;
    }
    return 0;
}