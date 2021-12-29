#include <bits/stdc++.h>
using namespace std;

long long n;

long long cata(long long n){
    if (n == 0){
        return 1;
    }
    long long num = 0;
    for (long long i = 0; i < n; i++){
        num += cata(i) * cata(n - i - 1);
    }
    return num;
}

int main(){
    freopen("VCATALAN.INP", "r", stdin);
    freopen("VCATALAN.OUT", "w", stdout);
    cin >> n;
    int count = 1;
    while (cata(count) != n){
        count++;
    }
    cout << count;
    return 0;
}