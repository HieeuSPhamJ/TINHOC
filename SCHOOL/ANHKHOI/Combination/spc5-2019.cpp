#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 10;
const int mod = 1e9 + 7;

long long dp[maxN][maxN];

void pascalTri(){
    for (int i = 0; i < maxN; i++){
        dp[i][i] = 1;
        dp[i][0] = dp[i][1] = 1;
    }
    for (int i = 1; i < maxN; i++){
        for (int j = 1; j < i; j++){
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            // cout << dp[i][j] << ' ';
        }
        cout << 1;
        // cout << endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    pascalTri();
    while(test--){
        int n, k;
        cin >> n >> k;
        cout << (dp[n][k] * dp[n][n -  k]) % mod;
        cout << endl;
    }
    return 0;
}