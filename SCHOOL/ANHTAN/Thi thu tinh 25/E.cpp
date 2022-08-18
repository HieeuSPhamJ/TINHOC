#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 3010;

int a[maxN];

int dp[maxN][maxN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int maxA = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        maxA = max(a[i], maxA);
    }

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= maxA; j++){
            dp[i][j] = 1;
        }
    }

    int ans = 0;
    
    for (int i = 2; i <= n; i++){
        for (int j = i - 1; j >= 1; j--){
            if (a[j] < a[i]){
                int diff = a[i] - a[j];
                dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                ans = max(ans, dp[i][diff]);
            }
        }
    }
    
    cout << ans;

    return 0;
}