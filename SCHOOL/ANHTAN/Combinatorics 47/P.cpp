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

int pre[maxN];
int suf[maxN];
int a[maxN];


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "*" + s;
    for (int i = 1; i <= n; i++){
        if (s[i] == '?'){
            a[i] = 0;
        }
        else if (s[i] == 'a'){
            a[i] = 1;
        }
        else if (s[i] == 'b'){
            a[i] = 2;
        }
        else if (s[i] == 'c'){
            a[i] = 3;
        }
    }

    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1];
        if (a[i] == 1 or a[i] == 0){
            pre[i]++;
        }
    }

    
    for (int i = n; i >= 1; i--){
        suf[i] = suf[i + 1];
        if (a[i] == 3 or a[i] == 0){
            suf[i]++;
        }
    }

    for (int i = 1; i <= n; i++){
        cout << pre[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++){
        cout << suf[i] << " ";
    }
    cout << endl;

    int ans = 0;

    for (int i = 1; i <= n; i++){
        if (a[i] == 0 or a[i] == 2){
            cout << i << " " << pre[i - 1] << " " << suf[i + 1] << endl;
            ans = add(ans, mul(pre[i - 1], suf[i + 1]));
        }
    }

    cout << ans;

    return 0;
}