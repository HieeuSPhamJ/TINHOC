#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;

int dp[maxN];

void aduuuu(){
    for (int i = 0; i < maxN; i++){
        dp[i] = 1e18;
    }
    dp[0] = 0;
    for (int i = 0; i < maxN; i++){
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        if (i > 1){
            for (int j = 2; j <= i and i * j < maxN; j++){
                dp[i * j] = min(dp[i * j], dp[i] + 1);
            }
        }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    aduuuu();
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}