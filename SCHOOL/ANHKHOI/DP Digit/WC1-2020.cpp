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
    int len = n.size() - 1;

    for (int i = 0; i <= 9; i++){
        int state = 0;
        if (i == n[0]){
            state = 1;
        }
        else if (i > n[0]){
            state = 2;
        }
        dp[0][i % k][i % k][i % k][state]++;
    }    
    for (int i = 0; i < len; i++){
        for (int thatNum = 0; thatNum < k; thatNum++){
            for (int sum = 0; sum < k; sum++){
                for (int pro = 0; pro < k; pro++){
                    for (int state = 0; state <= 2; i++){
                        if (dp[i][thatNum][sum][pro][state] == 0){
                            continue;
                        }
                        for (int dig = 0; dig <= 9; dig++){
                            int newState = state;
                            if (state == 1 and dig < n[i]){
                                newState = 0;
                            }
                            else if(state == 1 and dig > n[i]){
                                newState = 2;
                            }
                            long long ans = dp[i][thatNum][sum][pro][state];
                            (dp[i + 1][(thatNum + dig) % k][(sum + dig) % k][(pro * k) % k][newState] += ans) %= mod;

                        }
                        
                    }
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i <= len; i++){
        for (int state = 0; state <= 2; i++){
            if (i != len){
                ans += dp[i][0][0][0][state];
                ans %= mod;
            }
            else if (state <= 1){
                ans += dp[i][0][0][0][state];
                ans %= mod;
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