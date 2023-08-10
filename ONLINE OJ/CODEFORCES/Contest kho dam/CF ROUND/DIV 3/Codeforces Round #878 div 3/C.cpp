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
        int n, k, q;
        cin >> n >> k >> q;
        int last = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            if (x > q){
                last = i;
            }
            ans += (i - last - k + 1) * ((i - last) >= k);
            // cout << i << ' ' << last << endl;
        }

        cout << ans << endl;
    }
    return 0;
}