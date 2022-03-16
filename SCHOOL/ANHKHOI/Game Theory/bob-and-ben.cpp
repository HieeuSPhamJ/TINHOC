#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e3 + 10;

int n;
int dp[maxN];



int main(){
    int test;
    cin >> test;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 0;

    while(test--){
        cin >> n;
        int grundy = 0;
        for (int i = 1; i <= n; i++){
            int ai, bi;
            cin >> ai >> bi;
            if (ai <= 2){
                grundy = grundy ^ dp[ai];
            }
            else{
                grundy = grundy ^ ((ai + 1) % 2 + 1);
            }
        }
        if (grundy){
            cout << "BOB";
        }
        else{
            cout << "BEN";
        }
        cout << endl;
    }    
    return 0;
}
