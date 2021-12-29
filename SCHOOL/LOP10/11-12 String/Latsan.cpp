#include<bits/stdc++.h>
using namespace std;

long long n, m, a;

int main(){
    freopen ("Latsan.inp", "r", stdin);
    freopen ("Latsan.out", "w", stdout);
    cin >> n >> m >> a;
    cout << ((n / a) + bool(n % a)) * ((m / a) + bool(m % a));
    return 0;
}