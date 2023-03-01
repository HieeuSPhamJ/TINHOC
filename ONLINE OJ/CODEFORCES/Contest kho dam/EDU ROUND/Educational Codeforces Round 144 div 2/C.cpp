#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int mod = 998244353;
const int maxN = 1e6 + 10;
int fact[maxN];
int p2[maxN];
int p3[maxN];

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
    fact[0] = p2[0] = p3[0] = 1;
    for (int i = 1; i < maxN; i++){
        fact[i] = mul(fact[i - 1], i);
        p2[i] = p2[i - 1] * 2;
        p3[i] = p3[i - 1] * 3;
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
   return mul(fact[n], fastpow(mul(fact[k], fact[n - k]), mod - 2));
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;

    init();

    while(test--){
        int l, r;
        cin >> l >> r;
        int num = 0;
        for (int i = l; i <= r; i *= 2){
            num++;
        } 
        int ans = 0;
        int k = num - 1;
        for (int j = num - 1; j >= 0; j--){
            if (r / (p2[j] * p3[k - j]) < l){
                break;
            }
            ans = add(ans, mul(r / (p2[j] * p3[k - j]) - l + 1, C(k,j)));
        }
        cout << num << " " << ans << endl;
    }
    return 0;
}