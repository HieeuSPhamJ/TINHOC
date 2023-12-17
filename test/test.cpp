#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
const int maxN = 1e7 + 10;
int fact[maxN];


int add(int a, int b){
    return (a + b) % mod;
}
int subtr(int a, int b){
    return ((a + mod) - b) % mod; 
}
int mul(int a, int b){
    return (a * b) % mod;
}
void init(){
    fact[0] = 1;
    for (int i = 1; i < maxN; i++){
        fact[i] = mul(fact[i - 1], i);
    }
}
int fastpow(int n, int a){
    if (a == 1){
        return n;
    }
    int temp = fastpow(n, a / 2);
    int ans = mul(temp, temp);
    if (a % 2){
        return mul(ans, n);
    }
    else{
        return ans;
    }
}


int C(int n, int k){
    if (n < k){
        return 0;
    }
    return mul(fact[n], fastpow(mul(fact[k], fact[n - k]), mod - 2));
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int n = 100;
    int res = 0;
    for (int i = 1; i <= n; i++){
        for (int a = 1; a <= i; a++){
            for (int b = a; b <= i; b++){
                for (int c = b;c <= i; c++){
                    for (int d = c; d <= i; d++){
                        res++;
                    }
                }
            }
        }
    }
    cout << res * 2;
    return 0;
}