#include<bits/stdc++.h>
using namespace std;

const int maxN = 110;
const int maxK = 1e5 + 10;

int a[maxN];
int dp[maxK];

int main(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= k; i++){
        for (int j = 1; j <= n; j++){
            if (a[j] <= i){
                if (dp[i - a[j]] == 0){
                    dp[i] = 1;
                }
            }
        }
    }
    if (dp[k] == 0){
        cout << "Second"; 
    }
    else{
        cout << "First";
    }
    cout << endl;


    return 0;
}