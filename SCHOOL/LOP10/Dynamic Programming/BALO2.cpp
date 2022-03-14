#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e7 + 10;

int a[maxN];
int dp[maxN];
int last[maxN];


int main(){
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i] = a[i];
        last[i] = - 1;
    }
    for (int i = 1; i <= n; i++){
        dp[i] = max(dp[i - 1], dp[i]);
        for (int j = 1; j < i; j++){
            if (dp[j] + a[i] <= w){
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
            if (a[j] + a[i] <= w){
                dp[i] = max(dp[i], a[j] + a[i]);
            } 
        }
    }
    cout << dp[n];

    return 0;
}