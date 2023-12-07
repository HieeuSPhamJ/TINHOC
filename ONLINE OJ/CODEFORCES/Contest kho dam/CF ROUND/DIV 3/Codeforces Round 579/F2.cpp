#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int dp[110][60010];

bool cmp(ii a, ii b){
    return a.fi + a.se > b.fi + b.se;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("rank.inp", "r")) {
        freopen("rank.inp", "r", stdin);
        freopen("rank.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, rate;
    cin >> n >> rate;
    vector <ii> ls;
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        ls.push_back({a,b});
    }
    sort(rall(ls));
    int res = 0;
    priority_queue <ii> q;
    while(ls.size() and rate >= ls.back().fi){
        while(ls.size() and rate >= ls.back().fi){
            q.push({ls.back().se, ls.back().fi});
            ls.pop_back();
        } 
        while(q.size() and q.top().fi >= 0){
            res++;
            rate += q.top().fi;
            // cout << q.top().fi << endl;
            q.pop();
        }
    } 

    ls.clear();

    while(q.size()){
        ls.push_back(q.top());
        q.pop();
    }

    memset(dp, -1, sizeof(dp));
    sort(all(ls), cmp);
    // cout << rate << endl;
    // for (auto i: ls){
    //     cout << i.fi << " " << i.se << endl;
    // }
    dp[0][rate] = res;
    for (int i = 0; i < (int)ls.size(); i++){
        for (int r = 0; r <= 60000; r++){
            if (dp[i][r] == -1){
                continue;
            }
            dp[i + 1][r] = max(dp[i + 1][r], dp[i][r]);
            if (r + ls[i].fi >= 0 and r >= ls[i].se){
                int &nxt = dp[i + 1][r + ls[i].fi];
                nxt = max(nxt, dp[i][r] + 1);
                // cout << i << " " << r << ": " << dp[i][r] << endl;
                // cout << " =>" << i + 1 << " " << r + ls[i].fi << ": " << dp[i + 1][r + ls[i].fi] << endl;
            }
        }
    }

    for (int i = 1; i <= (int)ls.size(); i++){
        for (int r = 0; r <= 60000; r++){
            if (dp[i][r] != -1){
                // cout << i << " " << r << ": " << dp[i][r] << endl;
            }
            res = max(res, dp[i][r]);
        }
    }
    // cout << ma << endl;
    cout << res << endl;
    return 0;
}

/*
-292 29994
-297 29984
-296 29967
-300 29962
-296 29949
-298 29943
-296 29909
-297 29906
-295 29886
-298 29889
-299 29863
-293 29805
-295 29804
-300 29711
-295 29705
-295 29685
-287 29642
-297 29472
-297 29323
-283 29133
*/