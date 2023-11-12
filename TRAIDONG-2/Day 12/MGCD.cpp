#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;
const int mod = 1e9 + 7;

int fact[maxN];
int infact[maxN];
int cnt[maxN];

int add(int a, int b, int MOD = mod){
    return (a + b) % MOD;
}
int subtr(int a, int b, int MOD = mod){
    return ((a + MOD) - b) % MOD; 
}
int mul(int a, int b, int MOD = mod){
    return (a * b) % MOD;
}
int fastpow(int n, int a, int MOD = mod){
    if (a == 1){
        return n;
    }
    if (a == 0){
        return 1;
    }
    int temp = fastpow(n, a / 2, MOD);
    int ans = mul(temp, temp, MOD);
    if (a % 2){
        return mul(ans, n, MOD);
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
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int n;
    cin >> n;
    int MA = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        for (int j = 1; j * j <= x; j++){
            if (x % j == 0){
                cnt[j]++;
                // cout << j << endl;
                if (x / j != j){
                // cout << x / j << endl;
                    cnt[x / j]++;
                }
            }
        }
        MA = max(MA, x);
    }

    int res = 1;
    for (int i = 1; i <= MA; i++){
        cnt[i] = subtr(fastpow(2,cnt[i], mod - 1), 1, mod - 1);
        // cout << i << ": " << cnt[i] << endl;
    }
    for (int i = MA; i >= 2; i--){
        for (int j = i + i; j <= MA; j+=i){
            cnt[i] = subtr(cnt[i], cnt[j], mod - 1);
        }
        // cout << i << " " << cnt[i] << endl;
        res = mul(res, fastpow(i, cnt[i]));
    }

    cout << res << endl;
    return 0;
}

/*

10 1
9 0
8 0
7 0
6 0
5 2
4 1
3 0
2 1
1 2
2000


2 4 6
3 2 1
1 1 1

a^b = a^(b % (mod - 1))


4 5 10

4 => 4
5 => 5
10 => 10
4 5 10 => 1
4 5 =>  1
5 10 => 5
4 10 => 2
*/