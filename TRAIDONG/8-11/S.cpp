#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double int double
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;
const int mod = 1e9 + 7;

int add(int a, int b){
    return (a + b) % mod;
}
int subtr(int a, int b){
    return ((a + mod) - b) % mod; 
}
int mul(int a, int b){
    return (a * b) % mod;
}

int dp[maxN];
int onepa[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    onepa[0] = 1;
    dp[1] = onepa[1] = 26;

    for(int i = 2; i <= n; i++){
        onepa[i] = mul(onepa[i - 1], 26);
    }
    for(int i = 2; i <= n; i++){
        dp[i] = add(mul(onepa[(i + 2) / 2], i / 2), mul(onepa[(i + 1) / 2], (i + 1) / 2));
    }
    for(int i = 1; i <= n; i++){
        for(int j = i * 2; j <= n; j += i){
            dp[j] = subtr(dp[j], mul(dp[i], j / i));
        }
    }


    // for (int i = 1; i <= 10; i++){
    //     cout << dp[i] << endl;
    // }

    int ans = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j += i){
            ans = add(ans , dp[i]);
        }
    }
    cout<<ans;
    return 0;
}