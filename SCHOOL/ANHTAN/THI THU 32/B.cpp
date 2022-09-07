#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 60;

double a[maxN];
double dp[maxN][2];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while (test--){
        int n, total;
        cin >> n >> total;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            dp[i][0] = total;
            dp[i][1] = total;

        }
        
        for (int i = 2; i <= n; i++){
            for (int j = 1; j < i; j++){
                dp[i][0] = max({dp[i][0], dp[j][0], dp[j][1]});
                dp[i][1] = max(dp[i][1], dp[j][0] * (a[i] / a[j]) - dp[j][0] / 50);
            }
        }

        cout << fixed << setprecision(5) << max(dp[n][0], dp[n][1]) << endl;

    }
    
    return 0;
}