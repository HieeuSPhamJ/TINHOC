#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;


const int mod = 1e9 + 7;
const int maxN = 1e6 + 10;
int fact[maxN];
int infact[maxN];


int add(int a, int b){
    return (a + b) % mod;
}
int sub(int a, int b){
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
    // cout << n << "-" << k << endl;
    if (k > n){
        return 0;
    }
    return mul(fact[n], mul(infact[k], infact[n - k]));
    return mul(fact[n], fastpow(mul(fact[k], fact[n - k]), mod - 2));
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("input.inp", "r")) {
        freopen("input.inp", "r", stdin);
        freopen("A.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    map <int,int> pcnt;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (x == 1){
            cnt++;
            continue;
        }
        for (int j = 2; j * j <= x; j++){
            if (x % j == 0){
                cnt++;
                goto bru;
            }            
        }
        pcnt[x]++;
        bru:;
    }
    vector <int> ls;
    for (auto i: pcnt){
        if (i.se <= 1){
            cnt++;
            continue;
        }
        ls.push_back(i.se);
    }

    int res = 0;

    
    // cout << cnt << endl;
    int pre = 1;
    for (auto i: ls){
        // cout << i << " " << cnt << endl;
        int cur = mul(pre, C(cnt + i - 2,k - 2));
        res = add(res, cur);
        cnt += 2;
        pre = mul(pre, i + 1);
    }


    cout << sub(C(n, k), res) << endl;

    return 0;
}

/*

*/