#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 1e18 + 7;
const int maxN = 1e7 + 10;
int fact[maxN];
int infact[maxN];

int add(int a, int b){
    return (a + b);
}
int subtr(int a, int b){
    return (a - b); 
}
int mul(int a, int b){
    return (a * b);
}
int fastpow(int n, int a){
    if (a == 0){
        return 1;
    }
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
    return a / b;
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

int a[12];
int cnt[12];

int cal(){
    int res = 0;
    int n = 0;
    int under = 1;
    for (int i = 0; i <= 9; i++){
        n += cnt[i];
        // if (cnt[i]){
            // cout << i << ":" << cnt[i] << " ";
        // }
        under = mul(under, fact[cnt[i]]);
    }
    // cout << endl;
    for (int i = 1; i <= 9; i++){
        if (cnt[i]){
            int newUnder = mul(divi(under, fact[cnt[i]]), fact[cnt[i] - 1]);
            // cout << fact[n - 1] << " " << newUnder << endl;
            res = add(res, divi(fact[n - 1], newUnder));
        }
    }

    return res;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    init();
    for (int i = 0; i < s.size(); i++){
        a[s[i] - '0']++;
    }
    int ans = 0;
    for (cnt[0] = 0; cnt[0] <= a[0]; cnt[0]++){
    for (cnt[1] = 0; cnt[1] <= a[1]; cnt[1]++){
    for (cnt[2] = 0; cnt[2] <= a[2]; cnt[2]++){
    for (cnt[3] = 0; cnt[3] <= a[3]; cnt[3]++){
    for (cnt[4] = 0; cnt[4] <= a[4]; cnt[4]++){
    for (cnt[5] = 0; cnt[5] <= a[5]; cnt[5]++){
    for (cnt[6] = 0; cnt[6] <= a[6]; cnt[6]++){
    for (cnt[7] = 0; cnt[7] <= a[7]; cnt[7]++){
    for (cnt[8] = 0; cnt[8] <= a[8]; cnt[8]++){
    for (cnt[9] = 0; cnt[9] <= a[9]; cnt[9]++){
        for (int i = 0; i <= 9; i++){
            // cout << a[i] << ":" << cnt[i] << " ";
            if (a[i] >= 1 and cnt[i] == 0){
                goto bru;
            }
        }
        // cout << endl;
        (ans += cal()) %= mod;
        bru:;
    }   
    }   
    }   
    }   
    }   
    }   
    }   
    }   
    }   
    }

    cout << ans;

    return 0;
}