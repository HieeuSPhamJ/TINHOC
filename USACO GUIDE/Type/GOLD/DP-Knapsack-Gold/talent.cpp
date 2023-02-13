#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int inf = 1e18;

struct cow{
    int w, t;
};

cow a[400];

int dp[260][250010][3];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, W;
    cin >> n >> W;
    int T = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i].w >> a[i].t;
        T += a[i].t;
    }


    for (int i = 1; i <= n; i++){
        for (int t = 1; t <= T; t++){
            dp[i][t][0] = inf;
            dp[i][t][1] = inf;
            for (int j = 1; j < i; j++){
                dp[i][t][0] = min(dp[])
            }
        }
    }

    return 0;
}