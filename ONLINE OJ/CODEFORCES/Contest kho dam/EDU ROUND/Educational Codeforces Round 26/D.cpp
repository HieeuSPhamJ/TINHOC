#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 210;

ii a[maxN];
ii dp[3][maxN][5210];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int max2 = 0;
    int max5 = 0;
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        int x = inp;
        while(x % 2 == 0){
            x /= 2;
            a[i].fi++;
        }
        x = inp;
        while(x % 5 == 0){
            x /= 5;
            a[i].se++;
        }
        max2 += a[i].fi;
        max5 += a[i].se;
    }

    // for (int i = 1; i <= n; i++){
    //     cout << a[i].fi << " " << a[i].se << endl;
    // }

    dp[0][0][0] = {0,1};

    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= min(i,k); j++){
            for (int five = 0; five <= max5; five++){
                int temp = dp[(i - 1) % 2][j][five].fi;
                // cout << i << " " << j << " " << five << endl;
                int check = dp[(i - 1) % 2][j][five].se;
                if (j - 1 >= 0 and five - a[i].se >= 0){
                    if (dp[(i - 1) % 2][j - 1][five - a[i].se].se == 1){
                        temp = max(temp, dp[(i - 1) % 2][j - 1][five - a[i].se].fi + a[i].fi);
                        check = 1;
                    }
                }
                // cout << "Ans: " << temp << " " << check << endl;
                dp[i % 2][j][five].fi = temp;
                dp[i % 2][j][five].se = check;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= max5; i++){
        ans = max(ans, min(i,dp[n % 2][k][i].fi));
    }

    cout << ans;
    return 0;
}

/*
1 2
2 0
2 1
*/