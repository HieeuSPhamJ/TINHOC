#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

ii a[110];
int dp[maxN];

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
        for (int i = 1; i <= n; i++){
            cin >> a[i].fi;
            dp[i] = 1e18;
        }
        for (int i = 1; i <= n; i++){
            cin >> a[i].se;
        }
        a[0] = {0,0};
        
        for (int i = 1; i <= n; i++){
            if (a[i - 1].fi - a[i].fi >= a[i].se){
                dp[i] = (dp[i - 1]) + ((1 + a[i].se) * a[i].se) / 2;
            }
            for (int j = i - 1; j >= 1; j--){
                if (){
                    dp[i] = min(dp[i],);
                    break;
                }
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}