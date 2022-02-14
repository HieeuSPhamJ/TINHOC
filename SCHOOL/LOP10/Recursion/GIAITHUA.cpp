#include<bits/stdc++.h>
using namespace std;

long long Fac(long long n){
    if (n > 1){
        return n * Fac(n - 1);
    }
    return 1;
}

int main(){
    freopen("GIAITHUA.INP", "r", stdin);
    freopen("GIAITHUA.OUT", "w", stdout);
    long long n;
    cin >> n;
    cout << Fac(n);
    return 0;
}