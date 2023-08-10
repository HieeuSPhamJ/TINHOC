#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int n, A, B;

bool check(int s){
    while(s){
        if (s % 10 != A and s % 10 != B){
            return 0;
        }
        s /= 10;
    }
    return 1;
}

const int mod = 1e9 + 7;
const int maxN = 1e6 + 10;
int fact[maxN];
int infact[maxN];


int add(int a, int b){
    return (a + b) % mod;
}
int subtr(int a, int b){
    return ((a + mod) - b) % mod; 
}
int mul(int a, int b){
    return (a * b) % mod;
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
int divi(int a, int b){
    return mul(a, fastpow(b,mod - 2));
}
void init(){
    fact[0] = 1;
    for (int i = 1; i < maxN; i++){
        fact[i] = mul(fact[i - 1], i);
    }
    infact[maxN - 1] = fastpow(fact[maxN - 1], mod - 2);
    for (int i = maxN - 2; i >= 0; i--){
        infact[i] = mul(infact[i + 1], i + 1);
    }
    
}
int C(int n, int k){
    return mul(fact[n], mul(infact[k], infact[n - k]));
    return mul(fact[n], fastpow(mul(fact[k], fact[n - k]), mod - 2));
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    cin >> A >> B >> n;
    int res = 0;
    for (int i = 0; i <= n; i++){
        int sum = i * A + (n - i) * B;
        if (check(sum)){
            // cout << i << " " << n - i << " " << divi(fact[n],mul(fact[i], fact[n - i])) << endl;
            res = add(res, divi(fact[n],mul(fact[i], fact[n - i])));
        }
    }
    cout << res << endl;
    return 0;
}