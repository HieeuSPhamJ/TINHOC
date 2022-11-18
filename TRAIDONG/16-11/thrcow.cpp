#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 5000 + 10;

int n, test;
int a[maxN];
int dp[maxN][maxN];

void init(){
    for (int l = 1; l <= n; l++){
        map <int, int> cnt1;
        map <int, int> cnt2;
        cnt1[a[l]]--;
        for (int r = l; r <= n; r++){
            int ans = 0;
            if (l + 1 <= r){
                ans += dp[l + 1][r];
            }
            if (l <= r - 1){
                ans += dp[l][r - 1];
            }
            if (l + 1 <= r - 1){
                ans -= dp[l - 1][r - 1];
            }
            cnt1[a[r]]++;
            dp[l][r] = ans + cnt1[-(a[l] + a[r])] + cnt2[-(a[l])] + cnt2[-(a[r])];
            for (auto i: cnt1){
                cnt2[i.se + a[r]]++;
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
    // memset(dp, -1, sizeof(dp));
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    init();

    while(test--){
        int l, r;
        cin >> l >> r;
        cout << dp[l][r] << endl;
    }
    return 0;
}