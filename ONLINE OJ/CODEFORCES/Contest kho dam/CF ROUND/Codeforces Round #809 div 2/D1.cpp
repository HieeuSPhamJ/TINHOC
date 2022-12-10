#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> n >> k;
        int Ma = 0;
        int Mi = 1e18;
        for (int i = 1; i <= n; i++){
            int inp;
            cin >> inp;
            Ma = max(Ma, inp);
            Mi = min(Mi, inp);
        }   
        if (k > Ma){
            cout << 0;
            // cout << "*";
            cout << endl;
            continue;
        }
        Ma = Ma / k;
        int ans = 1e18;
        for (int i = 1; i <= k; i++){
            // if ()
            // cout << Ma - Mi / i << endl;
            // if ( Ma - Mi / i >= 0){
                ans = min(ans, abs(Ma - Mi / i));
            // }
        }
        // cout << Ma << endl;
        cout << ans << endl;

    }
    return 0;
}