#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int dp[19][6][4];

int cal(string s){
    int n = s.length();
    s = ' ' + s;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= 4; j++){
            for (int state = 0; state <= 2; state++){
                dp[i][j][state] = 0;
            }
        }
    }
    for (int i = 1; i <= 9; i++){
        int state = 0;
        if (s[1] - '0' == i){
            state = 1;
        }
        if (s[1] - '0' < i){
            state = 2;
        }
        dp[1][1][state]++;
    }
    
    for (int i = 1; i < n; i++){
        for (int j = 0; j <= 4; j++){
            for (int state = 0; state <= 2; state++){
                int cur = dp[i][j][state];
                if (cur == 0){
                    continue;
                }
                for (int d = 0; d <= 9; d++){
                    int nstate = state;
                    if (nstate == 1){
                        if (d > s[i + 1] - '0'){
                            nstate = 2;
                        }
                        else if (d < s[i + 1] - '0'){
                            nstate = 0;
                        }
                    }
                    dp[i + 1][j + (d != 0)][nstate] += cur;
                }
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 3; j++){
            res += dp[i][j][0];
            res += dp[i][j][1];
            if (i < n){
                res += dp[i][j][2];
            }
        }
    }
    return res;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int a, b;
        cin >> a >> b;
        cout << cal(to_string(b)) - cal(to_string(a - 1)) << endl;
        // cout << cal("65535") << endl; 
    }
    return 0;
}