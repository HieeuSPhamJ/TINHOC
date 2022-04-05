#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 19;

int a[maxN];

int main(){
    // int test;
    // cin >> test;
    // while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        long long ans = 0;
        for (int i = 1; i <= n - 2; i++){
            for (int j = i + 2; j <= n; j++){
                ans = max(ans, min(a[i], a[j]) * (abs(j - i) - 1ll));
            }
        }
        cout << ans;
        // cout << endl;
    // }
    return 0;
}