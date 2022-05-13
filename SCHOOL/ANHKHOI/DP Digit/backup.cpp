#include<bits/stdc++.h>
using namespace std;

const int maxI = 11;
const int maxK = 90;
const int maxState = 4;
const int mod = 1000000007;


long long dp[maxI][maxK][maxK][maxK][maxState];

void solve(){
    int k;
    string n;
    cin >> n >> k;
    if (k > 81){
        cout << 0;
        return;
    }
    int len = n.size();

    for (int i = 1; i <= 9; i++){
        int state = 0;
        if (i == n[0] - '0'){
            state = 1;
        }
        else if (i > n[0] - '0'){
            state = 2;
        }
        dp[1][i % k][i % k][i % k][state]++;
    }    
    for (int i = 1; i < len; i++){
        for (int thatNum = 0; thatNum < k; thatNum++){
            for (int sum = 0; sum < k; sum++){
                for (int pro = 0; pro < k; pro++){
                    for (int state = 0; state <= 2; state++){
                        if (dp[i][thatNum][sum][pro][state] == 0){
                            continue;
                        }
                        for (int dig = 0; dig <= 9; dig++){
                            int newState = state;
                            if (state == 1){
                                if (dig < n[i] - '0'){
                                    newState = 0;
                                }
                                else if (dig > n[i] - '0'){
                                    newState = 2;
                                }
                                
                            }
                            long long ans = dp[i][thatNum][sum][pro][state];
                            (dp[i + 1][(thatNum * 10 + dig) % k][(sum + dig) % k][(pro * k) % k][newState] += ans) %= mod;

                        }
                        
                    }
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= len; i++){
        if (i < len){
            for (int state = 0; state <= 2; state++){
                (ans += dp[i][0][0][0][state]) %= mod;
                
            }
        }
        else{
            for (int state = 0; state <= 1; state++){
                (ans += dp[i][0][0][0][state]) %= mod;
                
            }
        }
        
    }
    cout << ans;

}

int main(){
    int test;
    cin >> test;
    while(test--){
        solve();
        cout << endl;
    }
    return 0;
}