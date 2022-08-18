#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

struct iii{
    int t,d,p;
};

const int maxN = 110;

int dp[maxN][2010];

bool cmp(iii a, iii b){
    return a.d < b.d;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <iii> a;
    int maxD = 0;
    for (int i = 1; i <= n; i++){
        int t,d,p;
        cin >> t >> d >> p;
        maxD = max(maxD, d);
        a.push_back({t,d,p});
    }

    sort(a.begin(), a.end(), cmp);
    
    // for (auto i: a){
    //     cout << i.t << " " << i.d << " " << i.p << endl;
    // }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= maxD; j++){
            dp[i][j] = dp[i - 1][j];
            if (j - a[i - 1].t >= 0 and a[i - 1].d > j){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i - 1].t] + a[i - 1].p);
            }
        }
    }

    int ans = 0;

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= maxD; j++){
            // cout << dp[i][j] << ' ';
            ans = max(dp[i][j], ans);
        }
        // cout << endl;
    }

    cout << ans;
    return 0;
}