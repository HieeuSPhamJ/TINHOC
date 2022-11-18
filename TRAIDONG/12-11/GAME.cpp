#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
const int maxN = 1010;
int fact[maxN];
int infact[maxN];
int dp[maxN][maxN];


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
    int box, ball, k;
    cin >> ball >> box >> k;
    int sum = ball - k * box;
    sum = -sum;
    cout << sum << " " << box << endl;
    cout << C(sum + box - 1, box - 1);
    return 0;
}

/*

x1 + x2 + x3 = ball;
(xx1 + a1) + (xx2 + a2) + (xx3 + a3) = ball
xx1 + xx2 + xx3 = ball - (a1 + a2 + a3)
xx1 + xx2 + xx3 = ball - k * box

2 + 3 - 1, 2

*/