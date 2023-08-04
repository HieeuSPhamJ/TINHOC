#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1010;

int n;
double p, l;
pair <double,double> a[maxN];
double dp[maxN];

signed main(){
    // freopen("CHIENDICH.INP", "r", stdin);
    // freopen("CHIENDICH.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> p >> l;
    for (int i = 1 ; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
        a[i].se = 1.0 * l / a[i].se;
        // cout << a[i].fi << " " << a[i].se << endl;
    }

    for (int i = 1; i <= n; i++){
        dp[i] = 1e18;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        double tw = 0;
        double mt = 0;
        // cout << "With:" << i << endl;
        for (int j = i; j >= 1; j--){
            tw += a[j].fi;
            if (tw > p){
                break;
            }
            mt = max(mt, a[j].se);
            // if (dp[i] > dp[j - 1] + mt){
            //     cout << j << " " << dp[j - 1] + mt << endl;
            // }
            dp[i] = min(dp[i], dp[j - 1] + mt);
        }
        // cout << fixed << setprecision(2) << dp[i] << endl;
    }
    if (dp[n] >= 1e17){
        cout << -1 << endl;
        return 0;
    }
    cout << fixed << setprecision(2) << dp[n] << endl;
    return 0;
}