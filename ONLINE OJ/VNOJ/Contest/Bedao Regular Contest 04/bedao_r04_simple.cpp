#include<bits/stdc++.h>
using namespace std;

bool check(long long n){
    long long ans = 0;
    while(n > 0){
        ans += n % 10;
        n /= 10;
    }
    return !(ans % 10);
}

int main(){
    int n;
    cin >> n;
    long long ans = 18;   
    // for (int i = 1; i <= n; i++){
    //     ans += 9;
    //     while (check(ans)){
    //         // cout << ans << endl;
    //         ans += 1;
    //     }
    //     cout << i << ' ' << ans << endl;
    //     // cout << ans << endl;
    // }
    int count = 0;
    while(count < n){
        ans++;
        if (check(ans)){
            // cout << ans << endl;
            count++;
        }
    }
    cout << ans;
    
    return 0;
}