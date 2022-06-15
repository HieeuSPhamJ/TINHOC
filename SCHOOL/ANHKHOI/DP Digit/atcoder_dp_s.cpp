#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long dp[100001][110][3];

int main(){
    string s;
    int d;
    cin >> s >> d;

    // for (int i = 1; i <= 9; i++){
    //     int state = 0;
    //     if (i == s[0] - '0'){
    //         state = 1;
    //     }
    //     else if (i > s[0] - '0'){
    //         state = 2;
    //     }
    //     dp[1][i % d][state]++;
    // }

    for (int i = 1;i <= 9;i++){
        int state;
        if (i == s[0] - '0'){
            state = 1;
        }
        else if (i > s[0] - '0'){
            state = 2;
        }
        else{
            state = 0;
        }
        dp[1][i % d][state]++;
    }

    int len = s.size();

    for (int i = 0; i <= len; i++) {
        for (int rSum = 0; rSum < d; rSum++) {
            for (int state = 0; state <= 2; state++) {
                if (dp[i][rSum][state] == 0){
                    continue;
                }
                for (int dig = 0; dig <= 9; dig++){
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

                    int newrSum = (rSum + dig) % d;

                    (dp[i + 1][newrSum][newState] += dp[i][rSum][state]) %= mod;


                }

            }
        }
    }


    long long ans = 0;

    for (int i = 1; i <= len; i++){
        if (i < len){
            for (int state = 0; state <= 2; state++){
                (ans += dp[i][0][state] % mod) %= mod;
            }
        }
        else{
            for (int state = 0; state <= 1; state++){
                (ans += dp[i][0][state] % mod) %= mod;
            }
        }
    }

    
    cout << ans;

    return 0;
}


/*
    dp[i][rSum][state]

    i = i + 1
    rSum = (rSum + dig) % d
    
*/

