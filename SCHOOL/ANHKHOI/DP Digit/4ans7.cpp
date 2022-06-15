#include<bits/stdc++.h>
using namespace std;

long long dp[20][5][8][4];

void solve(){
    for (int i = 1; i < 20; i++){
        for (int r4 = 0; r4 < 4; r4++){
            for (int r7 = 0; r7 < 7; r7++){
                for (int state = 0; state <= 2; state++){
                    dp[i][r4][r7][state] = 0;
                }
            }
        }
    }

    string n;
    cin >> n;

    int len = n.length();

    for (int i = 1; i <= 9; i++){
        int state = 0;
        if (i == n[0] - '0'){
            state = 1;
        }
        else if (i > n[0] -  '0'){
            state = 2;
        }
        dp[1][i == 4][i == 7][state]++;

    }

    for (int i = 1; i <= len; i++){
        for (int r4 = 0; r4 < 4; r4++){
            for (int r7 = 0; r7 < 7; r7++){
                for (int state = 0; state <= 2; state++){
                    if (dp[i][r4][r7][state] == 0){
                        continue;
                    }
                    for (int dig = 0; dig <= 9; dig++){
                        int newState = state;
                        if (state == 1){
                            newState = 0;
                            if (dig == n[i] - '0'){
                                newState = 1;
                            }
                            else if (dig > n[i] -  '0'){
                                newState = 2;
                            }
                        }
                        int newR4 = (r4 + (dig == 4)) % 4;
                        int newR7 = (r7 + (dig == 7)) % 7;

                        dp[i + 1][newR4][newR7][newState] += dp[i][r4][r7][state];

                    }
                }
            }
        }
    }

    long long ans = 0;

    for (int i = 1; i <= len; i++){
        if (i < len){
            for (int state = 0; state <= 2; state++){
                ans += dp[i][0][0][state];
            }
        }
        else{
            for (int state = 0; state <= 1; state++){
                ans += dp[i][0][0][state];
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