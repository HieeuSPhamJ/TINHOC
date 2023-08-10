#include<bits/stdc++.h>
using namespace std;


int main(){ 
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> n >> k;
        int countBit[33];
        for (int i = 0; i <= 33; i++){
            countBit[i] = 0;
        }
        for (int i = 1; i <= n; i++){
            int inp;
            cin >> inp;
            int e = 31;
            while(inp > 0){
                countBit[e] += inp % 2;
                inp /= 2;
                e--;
            }
        }
        int ans = 0;
        for (int i = 1; i <= 31; i++){
            // cout << countBit[i];
            if (n - countBit[i] <= k){
                k = k - (n - countBit[i]);
                // cout << (n - countBit[i]);
                ans += pow(2, 31 - i);
            }
        }
        // cout << endl;
        cout << ans << endl;
    }
    return 0;
}