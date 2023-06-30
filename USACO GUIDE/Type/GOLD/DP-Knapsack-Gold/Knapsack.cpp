#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

struct good{
    int p,w,k;
};

good a[(int)1e5 + 10];

bool cmp(good x, good y){
    if (x.w == y.w){
        return x.p > y.p;
    }
    return x.w < y.w;
}

vector <int> sto[2010];
int dp[2010];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, W;
    cin >> W >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].p >> a[i].w >> a[i].k;
    }

    sort(a + 1, a + 1 + n, cmp);

    for (int i = 1; i <= n; i++){
        while(a[i].k and sto[a[i].w].size() < W / a[i].w){
            sto[a[i].w].push_back(a[i].p);
            a[i].k--;
        }

    }
    
    // for (int w = 1; w <= W; w++){
    //     if (sto[w].size() == 0){
    //         continue;
    //     }
    //     cout << w << ": ";
    //     for (auto p: sto[w]){
    //         cout << p << " ";
    //     }
    //     cout << endl;
    // }

    // cout << endl;

    int res = 0;
    for (int w = 1; w <= W; w++){
        for (auto p: sto[w]){
            for (int s = W - w; s >= 0; s--){
                dp[s + w] = max(dp[s + w], dp[s] + p);
                res = max(res, dp[s + w]);
                // cout << w << ' ' << p << ": " << s + w << " " << dp[s + w] << endl;
            }
        }
    }

    // for (int i = 1; i <= W; i++){
    //     cout << i << ": " << dp[i] << endl;
    // }

    cout << res << endl;
    return 0;
}