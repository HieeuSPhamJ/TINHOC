#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

int a[maxN];

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
        int ma = -1e18;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            ma = max(ma,a[i]);
        }
        if (n == 1){
            cout << a[1] << endl;
            continue;
        }
        if (n == 2){
            cout << max(a[1], a[2]) << endl;
            continue;
        }
        int par[3];
        par[0] = max(0ll,a[2]);
        par[1] = max(0ll,a[1]);
        int ans = max(a[1],a[2]);
        for (int i = 3; i <= n; i++){
            if (i % 2){
                int t = max(a[i] + par[1], a[i]);
                ans = max(ans, t);
                par[1] = max(par[1], t);
            }
            else{
                
                int t = max(a[i] + par[0], a[i]);
                ans = max(ans, t);
                par[0] = max(par[0], t);
            }
        }
        cout << ans << endl;
    }
    return 0;
}