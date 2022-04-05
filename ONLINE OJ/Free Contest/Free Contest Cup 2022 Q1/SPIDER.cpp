#include<bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

int main(){
    int test;
    cin >> test;
    while(test--){
        long long n;
        cin >> n;
        long long ans = 1;
        for (int i = 1; i <= n; i++){
            ans = ((ans * i) % mod * (i + 1)) % mod;

        }
        cout << ans;
        cout << endl;
        
    }
    return 0;
}