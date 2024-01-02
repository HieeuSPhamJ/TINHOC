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

int maximize(int &a, int b){
    if (a < b){
        a = b;
        return 1;
    }
    return 0;
}

const int maxN = 1e5 + 10;

struct dt{
    int we, pr, nu;
} a[maxN];
int dp[maxN];
priority_queue <ii> la[maxN];


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, W;
    cin >> n >> W;
    for (int i = 1; i <= n; i++){
        cin >> a[i].we >> a[i].pr >> a[i].nu;
    }
    int res = 0;

    for (int i = 1; i <= n; i++){
        // cout << "With: " << i << endl;
        for (int w = 0; w <= W; w++){
            while(la[w].size()){
                la[w].pop();
            }
        }
        for (int w = 0, co = 0; w <= W; w++){
            priority_queue <ii> &las = la[w % a[i].we];
            if (w % a[i].we == 0){
                co += a[i].pr;
            }
            // cout << "we: " << w << " " << co << endl;
            las.push({dp[w] - co, w + a[i].we * a[i].nu});
            // cout << w % a[i].we << " => " << dp[w] - co << " " << w + a[i].we * a[i].nu << endl;
            while(las.size() and las.top().se < w){
                // cout << w % a[i].we << " pop " << las.top().fi << endl;
                las.pop();
            }
            if (la[w % a[i].we].size()){
                if (maximize(dp[w], la[w % a[i].we].top().fi + co)){
                    // cout << "res " << dp[w] << " " << la[i % a[i].we].top().se - a[i].we * a[i].nu << endl;
                }
            }
            maximize(res, dp[w]);
        }
    }


    cout << res << endl;
    return 0;   
}

/*
dp[w] = dp[w - c * k]

*/