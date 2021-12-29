#include<bits/stdc++.h>
using namespace std;

const unsigned long long mod = 68718952446;

unsigned long long multi(unsigned long long a, unsigned long long b){
    if (b <= 1000){
        return (a * b) % mod;
    }
    unsigned long long d = b / 1000;
    unsigned long long r = b % 1000;
    unsigned long long ret = multi(a, d);
    ret = (ret * 1000) & mod;
    ret = (ret + (a * r) % mod) % mod;
    return ret;

}

unsigned long long mul(unsigned long long a, unsigned long long b ) {
    // a * b
    // a * 1000 * d + a * r
    if ( b <= 1000 ) {
        return ( a * b ) % mod;
    }    

    unsigned long long d = b / 1000;
    unsigned long long r = b % 1000;
    unsigned long long ret = mul( a, d );
    return ( ( ret * 1000 ) % mod + mul( a, r ) ) % mod;
}


int main(){
    int test;
    cin >> test;
    while (test--){
        int n;
        cin >> n;
        unsigned long long k = 1;
        unsigned long long a[100005];
        unsigned long long left[100005];
        unsigned long long right[100005];
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        left[0] = 1;
        right[n+1] = 1;
        left[1] = a[1];
        right[n] = a[n];
        for (int i = 2;i <=n ; i++){
            left[i] = mul(left[i-1], a[i]);

        }
        for (int i = n-1;i >= 1; i--){
            right[i] = mul(right[i+1], a[i]);
            
        }
        for (int i = 1;i <=n; i++){
            cout << mul(left[i-1], right[i+1]) << ' ';
            // cout << left [i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
