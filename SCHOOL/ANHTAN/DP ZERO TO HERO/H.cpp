#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
int dp[maxN];

bool check(int x){
    if(x == 0){
        return false;
    }
    int y = sqrt(x);
    return y * y == x;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int res = 1;
    for (int i = 1; i <= n; i++){
        dp[i] = 1;  
        for (int j = i - 1; j >= 1 and i - j <= 10; j--){
            int del = abs(a[i] - a[j]);
            if (check(del)){
                if (dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
        }
        // cout << dp[i] << " ";
        res = max(res,dp[i]);
    }
    // cout << endl;
    cout << res << endl;
    return 0;
}

/*
2 6 2 31 22 11 26
2 3 4 4  5  6  6
2, 6, 31, 32, 26


*/