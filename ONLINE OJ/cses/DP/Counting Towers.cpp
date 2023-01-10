#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
const int maxN = 1e6 + 10;

int dp[maxN][3];


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    dp[1][1] = 1;
    dp[1][0] = 1;

    for (int i = 2; i < maxN; i++){
        (dp[i][1] = 2 * dp[i - 1][1] + dp[i - 1][0]) %= mod;
        (dp[i][0] = dp[i - 1][1] + 4 * dp[i - 1][0]) %= mod;
    }

    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % mod << endl;
    }
    return 0;
}