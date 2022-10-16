#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
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
        int n, q;
        cin >> n >> q;
        int a[3] = {0};
        int ans = 0;
        for (int i = 1; i <= n; i++){
            int inp;
            cin >> inp;
            ans += inp;
            a[inp % 2]++;
        }
        while(q--){
            int type , inp;
            cin >> type >> inp;
            int org = a[type];
            int temp = type + inp;
            ans += a[type] * inp;
            a[temp % 2] += a[type];
            a[type] -= org;
            cout << ans << endl;
        }


    }
    return 0;
}