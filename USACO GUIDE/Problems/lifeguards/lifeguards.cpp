#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

ii a[maxN];
int dp[maxN][105];

int len(ii a){
    return a.se - a.fi + 1;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    
    sort(a + 1, a + 1 + n);
    vector <ii> lists;
    for(int i = 1; i <= n; i++){
        if (lists.empty()){
            lists.push_back(a[i]);
        }
        else{
            ii t = lists.back();
            if (a[i].se > t.se){
                lists.push_back(a[i]);
            }
            else{
                k--;
            }
        }
    }
    dp[1][1] = 0;
    dp[1][0] = len(a[1]);
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= k; j++){
            int now = dp[i][j];
            if (a[i].se < a[i + 1].fi){
                dp[i + 1][j] = max(dp[i + 1][j], now + len(a[i + 1])); 
            }
            else{
                dp[i + 1][j] = max(dp[i + 1][j], now + len(a[i + 1]) - (a[i].se - (a[i + 1].fi - 1)));
            }
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], now);
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= k; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[n][k] << endl;

    return 0;
}