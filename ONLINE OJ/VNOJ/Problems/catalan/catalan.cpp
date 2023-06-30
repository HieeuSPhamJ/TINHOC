#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int a[32];
int dp[32][32];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    n = n * 2 + 1;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[n][0] = 1;
    for (int i = n; i >= 1; i--){
        for (int d = 0; d <= n / 2; d++){
            int cur = dp[i][d];
            if (cur == 0){
                continue;
            }
            if (d){
                dp[i - 1][d - 1] += cur;
            }
            dp[i - 1][d + 1] += cur;
        }
    }

    
    // for (int j = 0; j <= 4; j++){
    //     for (int i = 1; i <= n; i++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int l = 1;
    int r = dp[1][0];
    for (int i = 2; i <= n; i++){
        if (a[i] == a[i - 1] + 1){
            if (a[i - 1]){
                l += dp[i][a[i - 1] - 1];
            }
        }
        else{
            r -= dp[i][a[i - 1] - 1];
        }
    }
    cout << l << endl;
    int k;
    cin >> k;
    l = 1;
    r = dp[1][0];
    int last = 0;
    cout << 0 << " ";
    for (int i = 2; i <= n; i++){
        if (last == 0){
            cout << last + 1 << " ";
            last++;
            continue;
        }
        if (k <= r - dp[i][last + 1]){
            r -= dp[i][last + 1];
            cout << last - 1 << " ";
            last--;
            continue;
        }
        l += dp[i][last - 1];
        cout << last + 1 << " ";
        last++;
        continue;
    }


    return 0;
}

/*
12
0 1 2 3 2 1 2 1 0
12
0 1 2 3 2 1 2 1 0
*/