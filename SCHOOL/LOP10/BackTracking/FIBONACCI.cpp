#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("FIBONACCI.INP", "r", stdin);
    freopen("FIBONACCI.OUT", "w", stdout);
    long long n;
    cin >> n;
    long long a = 1, b = 1;
    for (int i = 3; i <= n; i++){
        long long temp = a;
        a += b;
        b = temp;
    }
    cout << a;
    return 0;
}