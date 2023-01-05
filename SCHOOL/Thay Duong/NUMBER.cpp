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
    if (k > n){
        return 0;
    }
    if (k == 2){
        return (n * (n - 1)) / 2;
    }
    return (n * (n - 1) * (n - 2)) / 6;
}

int le[maxN];
int chan[maxN];

signed main(){
    freopen("NUMBER.INP", "r", stdin);
    freopen("NUMBER.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int test;
    cin >> test;
    while(test--){
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++){
            le[i] = le[i - 1];
            chan[i] = chan[i - 1];
            int x;
            cin >> x;
            x %= 2;
            if (x){
                le[i]++;
            }
            else{
                chan[i]++;
            }
        }
        while(q--){
            int left, right;
            cin >> left >> right;
            int c = chan[right] - chan[left - 1];
            int l = le[right] - le[left - 1];
            // cout << l << "-" << c << ":";
            cout << C(l,3) + C(c,2) * l << " "; 
        }   
        cout << endl;
    }



    return 0;
}