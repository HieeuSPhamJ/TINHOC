#include<bits/stdc++.h>
using namespace std;

long long dp[11][84][84][84][4];

void solve(){
    string n;
    int k;
    cin >> n >> k;

    int len = n.size();

    for (int i = 0; i <= 9; i++){
        int state = 0;
        if (i == n[0] - '0'){
            state = 1;
        }
        else if (i > n[0] - '0'){
            state = 2;
        }

        dp[0][i % k][i % k][i % k][state]++;
    }

    for (int i = 1; i < len; i++){
        for (int num = 0; num < k; num++){
            
        }
    }
}



main(){
    int test;
    cin >> test;
    while(test--){
        solve();
        cout << endl;
    }

    return 0;
}