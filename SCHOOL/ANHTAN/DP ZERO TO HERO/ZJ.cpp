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
int dp[maxN];

bool cmp(ii a, ii b){
    if (a.fi > b.fi){
        return 1;
    }
    return 0;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + 1 + n, cmp);
    dp[0] = 0; 

    
    // for (int i = 1; i <= n; i++){
    //     cout << a[i].fi << ' ' << a[i].se << endl;
    // }

    for (int i = 1; i <= n; i++){
        dp[i] = 1e18;
        // cout << "With: " << i << endl;
        for (int j = i - 1, cost = 0; j >= 0; j--){
            // if (dp[i] > dp[j] + a[i].se + cost){
            //     cout << j << " " << dp[j] + a[i].se + cost << endl;
            // }
            dp[i] = min(dp[i], dp[j] + a[i].se + cost);
            cost += abs(a[i].fi - a[j].fi);
        }
        // cout << dp[i] << endl;
    }
    
    cout << dp[n] << endl;

    return 0;
}

/*
3 2 1
4 3 
*/