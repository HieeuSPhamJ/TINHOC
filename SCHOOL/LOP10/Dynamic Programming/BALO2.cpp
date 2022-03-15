#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e4 + 10;
int a[maxN];
int p[maxN];
long long dp[maxN][maxN];
vector <int> vect[maxN];


int main(){
    int n, maxW;
    cin >> n >> maxW;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> p[i];
    }
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= maxW; j++){
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= maxW; j++){
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i]){
                if (dp[i][j] < dp[i - 1][j - a[i]] + p[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + p[i]);

            }
            // cout << dp[i][j] << ' ';
        }
        // cout << endl;
    }
    cout << dp[n][maxW];

    return 0;
}