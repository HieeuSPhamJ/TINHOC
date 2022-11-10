#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;

int dp[1010][1010];

void init(){
    dp[0][0] = 1;
    for (int i = 0; i <= 1000; i++){
        for (int j = 0; j <= i; j++){
            int now = dp[i][j];
            if (now == 0){
                continue;
            }
            //add to last
            (dp[i + 1][j] += now) %= mod;
            //add to last and swap to not acp
            (dp[i + 1][j + 1] += now * (i - j)) %= mod;
            //add to last and swap to acp
            (dp[i + 1][j] += now * j) %= mod;
        }   
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();

    // for (int i = 0; i <= 10; i++){
    //     for (int j = 0; j <= 10; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int n, k;
    cin >> n >> k;
    cout << dp[n][k];
    return 0;
}