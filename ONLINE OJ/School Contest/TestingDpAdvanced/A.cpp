#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxI = 1e4 + 10;
const int maxD = 100;
const int maxState = 3;
const int mod = 1e9 + 7;

string n;
int d;
int dp[maxI][maxD][maxState];

main(){

    cin >> n >> d;

    // cout << n << ' ' << d << endl;

    for (int i = 1; i <= 9; i++){
        int state = 0;
        if (i == n[0] - '0'){
            state = 1;
        }
        else if (i > n[0] - '0'){
            state = 2;
        }

        dp[1][i % d][state]++;
    }

    int len = n.size();

    for (int i = 1; i <= len; i++){
        for (int rD = 0; rD < d; rD++){
            for (int state = 0; state <= 2; state++){
                if (dp[i][rD][state] == 0){
                    continue;
                }
                for (int dig = 0; dig <= 9; dig++){
                    int newState = state;
                    if (state == 1){
                        newState = 0;
                        if (dig == n[i] - '0'){
                            newState = 1;
                        }
                        else if (dig > n[i] - '0'){
                            newState = 2;
                        }
                    }
                    (dp[i + 1][(rD + dig) % d][newState] += dp[i][rD][state]) %= mod;
                    // cout << i << ' ' << rD << ' ' << state << endl;
                    // cout << dp[i][rD][state] << ' ' << dig << endl;
                    // cout << i + 1 << ' ' << (rD + dig) % d << ' ' << newState << ' ' << dp[i + 1][(rD + dig) % d][newState] << endl;
                }
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= len; i++){
        if (i == len){
            for (int state = 0; state <= 1; state++){
                (ans += dp[i][0][state]) %= mod;
            }

            continue;
        }
        for (int state = 0; state <= 2; state++){
            (ans += dp[i][0][state]) %= mod;
        }
    }

    cout << ans;

    return 0;
}