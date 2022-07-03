#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int mod = 1e9 + 7;
const int maxN = 2 * 1e7 + 100;

long long factor[maxN];
long long reFactor[maxN];


void init(){
    factor[0] = 1;
    for (int i = 1; i < maxN; i++){
        factor[i] = factor[i - 1] * i;
        factor[i] %= mod;
        // cout << factor[i] << endl;
    }

}

long long fastPow(long long n, long long a){
    if (a == 1){
        return n;
    }
    long long temp = fastPow(n, a / 2) % mod;
    if (a % 2 == 1){
        return (((temp * temp) % mod) * n) % mod;
    }
    return (temp * temp) % mod;
}

long long kCn(long long k, long long n){
    return (factor[n] * fastPow((factor[k] * factor[n - k]) % mod, mod - 2)) % mod;
}


int main(){
    init();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    long long ans = 0;
    // cout << kCn(2, 10);
    for (int i = 0; i <= min(n, m); i++){
        ans += (kCn(i, n + m - i) * kCn(n - i, m + n - 2 * i)) % mod;
        ans %= mod;
    }
    
    cout << ans;
    return 0;
}