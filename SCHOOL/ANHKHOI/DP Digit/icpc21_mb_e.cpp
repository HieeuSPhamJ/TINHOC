#include<bits/stdc++.h>
using namespace std;

bool prime[200];
long long dp[20][140][140][3];

void Eras(){
    prime[0] = prime[1] = 1;
    for (int i = 1; i * i <= 200; i++){
        if (!prime[i]){
            for (int e = 2; e * i < 200; e++){
                prime[e * i] = 1;
            }
        }
    }

    // for (int i = 1; i <= 20; i++){
    //     cout << prime[i] << ' ';
    // }
}

int main(){
    Eras();

    string s;
    cin >> s;
    string n = "";
    for (int i = 0; i < s.size(); i++){
        n = s[i] + n;
    }
    n = '0' + n + '0';
    // cout << n << endl;
    int len = n.size() - 2;

    dp[0][0][0][0] = 1;

    // for (int i = 0; i <= 9; i++){
    //     for (int j = 0; j <= 9; j++){
    //         if ((i + j * 2) / 10 == n[1] - '0'){
    //             dp[1][i][j][(i + j * 2) / 10]++; 

    //             // cout << i << ' ' << j << ' ' << (i + j * 2) / 10 << ": " << dp[1][i][j][(i + j * 2) / 10] << endl;
    //         }
    //     }
    // }

    for (int i = 0; i <= len; i++){
        for (int sumx = 0; sumx <= 135; sumx++){
            for (int sumy = 0; sumy <= 135; sumy++){
                for (int rem = 0; rem <= 2; rem++){
                    if (dp[i][sumx][sumy][rem] == 0){
                        continue;
                    }
                    for (int digY = 0; digY <= 9; digY++){
                        for (int temp = 0; temp <= 2; temp++){
                            int digX = (10 * temp + n[i + 1] - '0') - (2 * digY + rem);
                            if (digX < 0 or digX > 9){
                                continue;
                            }
                            int newSumx = sumx + digX;
                            int newSumy = sumy + digY;
                            int newRem = (digX + 2 * digY + rem) / 10;
                            // cout << dp[i][sumx][sumy][rem] << ' ';
                            dp[i + 1][newSumx][newSumy][newRem] += dp[i][sumx][sumy][rem];
                        }
                    }
                }
            }  
        }
    }

    long long ans = 0;
    for (int sumx = 0; sumx <= 135; sumx++){
        for (int sumy = 0; sumy <= 135; sumy++){
            if (!prime[sumx] and !prime[sumy]){
                // cout << dp[len + 1][sumx][sumy][0] << ' ';
                ans += dp[len + 1][sumx][sumy][0];
            }
        }
    }

    cout << ans;

    return 0;
}