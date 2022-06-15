#include<bits/stdc++.h>
// #define int32 long long
// #define long long long long
#define endl "\n"
using namespace std;

const long long maxN = 102;
const long long mod = 1e9 + 7;

long long dp[maxN][maxN];
long long C[maxN][maxN];

void preCal(){
    for (long long i = 0; i < maxN; i++){
        C[i][0] = C[i][i] = 1;
    }
    for (long long i = 1; i < maxN; i++){
        C[i][0] = C[i][i] = 1;
        for (long long j = 1; j < i; j++){
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }

    dp[1][0] = dp[2][0] = 0;
    dp[1][1] = dp[2][1] = 1;
    

    for (long long i = 3; i < maxN; i++){
        for (long long j = 1; j < i; j++){
            dp[i][j] = dp[i - 1][j];
            for (long long x = 1; x < i - 1; x++){
                for (long long y = 1; y < j; y++){
                    (dp[i][j] += (((dp[x][y] * dp[i - 1 - x][j - y]) % mod) * ((C[i - 3][x - 1] * (i - 2)) % mod) % mod)) %= mod;
                }
            }
        }
    }
    
}

int main(){
    preCal();
    long long test;
    cin >> test;
    while(test--){
        long long n, a;
        cin >> n >> a;
        cout << (dp[n - 1][a] * (n - 1) * n) % mod;

        cout << endl;
    }
    return 0;  
}