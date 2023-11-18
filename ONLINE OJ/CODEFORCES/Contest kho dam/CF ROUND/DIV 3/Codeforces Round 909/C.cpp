#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int res = -1e18;
        for (int i = 1, la = -1, sum = -1e18; i <= n; i++){
            int x;
            cin >> x;
            if (la != -1 and abs(x) % 2 != la){
                sum = max({sum + x, x});
            }
            else{
                sum = x;
            }
            // cout << i << " "<< sum << endl;
            res = max(res, sum);
            la = abs(x) % 2;
        }

        cout << res << endl;
    }
    return 0;
}