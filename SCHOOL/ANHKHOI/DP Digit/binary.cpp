#include<bits/stdc++.h>
using namespace std;

int dp[40][40][4];

void solve(int n, int k){
    string s;
    while(n > 0){
        s = char(n % 2 + '0') + s;
        n /= 2;
    }
    // cout << s << endl;
    int len = s.size();
    dp[1][0][1] = 1;

    for (int i = 1; i <= len; i++){
        for (int totalO = 0; totalO < k; totalO++){
            for (int state = 0; state <= 2; state++){
                // cout << i << ' ' << totalO << ' ' << state << endl;
                if (dp[i][totalO][state] == 0){
                    continue;
                }
                for (int dig = 0; dig <= 1; dig++){
                    int newTotalO = totalO + !dig;
                    int newState = state;
                    if (state == 1){
                        newState = 0;
                        if (dig == s[i] - '0'){
                            newState = 1;
                        }
                        else if (dig > s[i] - '0'){
                            newState = 2;
                        }
                    }
                    // cout << "---" << dig << ' ' << totalO << ' ' << state << ' ' << dp[i][totalO][state] << endl;
                    dp[i + 1][newTotalO][newState] += dp[i][totalO][state];
                }
            }
        }
    }

    long long ans = 0;

    for (int i = 1; i <= len; i++){
        if (i < len){
            for (int state = 0; state <= 2; state++){
                ans += dp[i][k][state];
                // cout << dp[i][k][state] << ' ';
            }
        }
        else{
            for (int state = 0; state <= 1; state++){
                ans += dp[i][k][state];
                // cout << dp[i][k][state] << ' ';
            }
        }
    }
    cout << ans;
}

int main(){
    int n, k;
    cin >> n >> k;
    solve(n, k);

    return 0;
}