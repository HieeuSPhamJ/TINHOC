#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
    freopen("binhphuong.INP", "r", stdin);
    freopen("binhphuong.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    if (N <= 8){
        int res = 0;
        for (int n = 1; n <= N; n++){
            map <int,int> dp;
            for (int i = 1; i <= n; i++){
                dp[i] = 1e18;
            }
            for (int i = 0; i <= n; i++){
                int cur = dp[i];
                for (int j = 1; j * j + i <= n; j++){
                    dp[i + j * j] = min(dp[i + j * j], cur + 1);
                }
            }
            res = max(res, dp[n]);
        }
        cout << res << endl;
    }
    else{
        cout << 4 << endl;
    }
    return 0;
}

/*
1 => 1
2 => 2
3 => 3
4 => 3
5 => 3
6 => 3
7 => 4
8 => 4
9 => 

 + 2^2
*/