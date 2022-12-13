#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    int dp[100];
    dp[0] = 0;
    for (int i = 1; i <= 9; i++){
        dp[i] = dp[i - 1] + 9;
    }
    while(test--){
        string s;
        cin >> s;
        cout << dp[(int)s.size() - 1] + s[0] - '0' << endl;
    }
    return 0;
}