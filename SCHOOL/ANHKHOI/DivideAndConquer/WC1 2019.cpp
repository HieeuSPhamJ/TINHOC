#include<bits/stdc++.h>
using namespace std;

const long long mod = 68718952446;

long long multi(long long a, long long b){
    if (b <= 1000){
        return (a * b) % mod;
    }
    long long d = b / 1000;
    long long r = b % 1000;
    long long ret = multi(a, d);
    ret = (ret * 1000) & mod;
    ret = (ret + (a * r) % mod) % mod;
    return ret;

}


int main(){
    int test;
    cin >> test;
    while (test--){
        int n;
        cin >> n;
        long long k = 1;
        long long a[100005];
        long long left[100005];
        long long right[100005];
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        left[0] = 1;
        right[n+1] = 1;
        left[1] = a[1];
        right[n] = a[n];
        for (int i = 2;i <=n ; i++){
            left[i] = multi(left[i-1], a[i]);

        }
        for (int i = n-1;i >= 1; i--){
            right[i] = multi(right[i+1], a[i]);
            
        }
        for (int i = 1;i <=n; i++){
            cout << (left[i-1] * right[i+1]) % mod << ' ';
            // cout << left [i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
