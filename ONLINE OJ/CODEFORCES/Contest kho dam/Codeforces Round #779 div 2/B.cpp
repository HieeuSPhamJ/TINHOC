#include<bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

/*
    0 1 0 4 0 36 665702330
*/


void solve(){
    int n;
    cin >> n;
    long long ans = 1;
    if (n % 2){
        cout << 0;
        return;
    }
    for (int i = 1; i <= n / 2; i++){
        ans = (ans * i) % mod;
    }
    cout << (ans * ans) % mod;

    
    
}

int main(){
    int test;
    cin >> test;
    while(test--){
        solve();
        cout << endl;
    }

    return 0;
}

