#include<bits/stdc++.h>
using namespace std;

const int maxN = 10000010;
const long long mod = 1e9 + 7;

long long Factorial[maxN];
long long sumFac[maxN];
long long sumSumFac[maxN];

void Setup(){
    Factorial[0] = 1;
    for (int i = 1; i <= maxN - 1; i++){
        Factorial[i] = ((Factorial[i - 1] % mod) * (i % mod)) % mod;
    }
    sumFac[0] = 1;
    for (int i = 1; i <= maxN - 1; i++){
        sumFac[i] = ((sumFac[i - 1] % mod) + (Factorial[i] % mod)) % mod;
    }
    sumSumFac[0] = 1;
    for (int i = 1; i <= maxN - 1; i++){
        sumSumFac[i] = ((sumSumFac[i - 1] % mod) + (sumFac[i] % mod)) % mod;
    }
}

long long Cal(long long n){
    long long ret = Factorial[n];
    long long retFail = (2LL * sumFac[n - 1]) % mod;
    retFail = retFail - sumSumFac[n - 2] - 1LL;
    retFail = (retFail + mod) % mod;
    ret = ret - retFail;
    ret = (ret + mod) % mod;
    // return ret;
    return ((( Factorial[n] % mod) - (((2LL * sumFac[n - 1]) % mod) - (sumSumFac[n - 2] - 1LL + mod) % mod) + mod) + 2) % mod;
}

int main(){
    Setup();
    int test;
    cin >> test;
    while(test--){
        long long n;
        cin >> n;
        if (n <= 2){
            cout << 0;
        }
        else{ 
            cout << Cal(n);

        }
        cout << endl;
    }
    // for (int i = 2; i <= maxN - 10; i++){
    //     // cout << Cal(i) << endl;
    //     if (Cal(i) < 0){
    //         cout << Factorial[i] << ' ' << sumFac[i - 1] << ' ' << sumSumFac[i - 2];
    //         cout << endl;
    //         cout << i << ' ' << Cal(i);
    //         break;
    //     }
    // }
    return 0;
}