#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e6;

int dp[maxN];
int last[30];

/*
bmefbmuyw
111122222
*/

void Solve(){
    string a;
    cin >> a;
    int n = a.size();
    a = " " + a;
    dp[0] = 1;
    dp[1] = 1;
    // cout << dp[1] << ' ';
    last[a[1]] = 1;
    for (int i = 1; i <= n; i++){
        int temp = -1;
        for (int j = i - 1; j >= 1; j--){
            if (a[j] == a[i]){
                temp = j;
                break;
            }
        }
        dp[i] = dp[i - 1] + 1;
        if (temp != -1){
            dp[i] = max(dp[i],dp[temp] + 1);
        }

        cout << dp[i] << ' ' << temp << endl;
        
    }
    // cout << endl;
    cout << n - dp[n];
}


int main(){
    int test;
    cin >> test;
    while(test--){
        memset(last, 0, sizeof(last));
        Solve();
        cout << endl;
    }

    return 0;
}
