#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
// #define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 5010;

int a[maxN];
int cntTri[maxN][maxN];
int dp[maxN][maxN];

void solve(int l, int r){
    if (l > r){
        dp[l][r] = 0; 
        return;
    }
    if (r - l + 1 <= 2){
        dp[l][r] = 0; 
        return;
    }
    if (dp[l][r] != -1){    
        // cout << l << " " << r << " " << dp[l][r]<< endl;
        return;
    }
    solve(l + 1, r);
    solve(l, r - 1);
    solve(l + 1, r - 1);
    dp[l][r] = cntTri[l][r];
    dp[l][r] += dp[l + 1][r] + dp[l][r - 1] - dp[l + 1][r - 1];
    // cout << l << " " << r << " " << dp[l][r]<< endl;
}

signed main(){
    // freopen("threesum.in", "r", stdin);
    // freopen("threesum.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    // memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++){
        unordered_map <int,int> cnt;
        for (int j = i + 2; j <= n; j++){
            cnt[a[j - 1]]++;
            cntTri[i][j] += cnt[-(a[i] + a[j])];
            // cout << i << " " << j << " " << cntTri[i][j] << endl;
        }
    }

    for (int i = n; i >= 1; i--){
        for (int j = i; j <= n; j++){
            dp[i][j] = cntTri[i][j];
            dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            // cout << i << " " << j << endl;
        }
    }

    while(test--){
        int l, r;
        cin >> l >> r;
        // solve(l, r);
        cout << dp[l][r] << endl;
    }
    return 0;
}