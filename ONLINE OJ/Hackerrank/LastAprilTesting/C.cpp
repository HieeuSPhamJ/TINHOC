#include<bits/stdc++.h>
using namespace std;

long long x, n, mod;


long long calPow(long long x, long long n){
    if (n == 0){
        return 1;
    }
    if (n % 2 == 0){
        long long tempPow = calPow(x, n / 2) % mod;
        tempPow = tempPow * tempPow;
        return tempPow % mod;
    }
    return (calPow(x, n - 1) * x % mod) % mod;
}

long long Solve(long long x, long long n){
    if (n == 0){
        return 1;
    }
    if (n % 2 == 0){
        return (Solve(x, n - 1) + calPow(x, n)) % mod;
    }
    long long tempSolve = Solve(x, n / 2);
    tempSolve = (tempSolve * (1 + calPow(x, n / 2 + 1)) % mod) % mod;
    return tempSolve % mod;
}

int main(){
    int test;
    cin >> test;
    while (test--){
        cin >> x >> n >> mod;
        cout << Solve(x, n) << endl;
    }


    return 0;
}