#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 2e5 + 10;
const int mod = 1e9 + 7;

int n;

int add(int a, int b){
    return (a + b) % mod;
}

int mul(int a, int b){
    return (a * b) % mod;
}

int fastpow(int n, int k){
    if (k == 0){
        return 1;
    }
    if (k == 1){
        return n;
    }
    int t = fastpow(n, k / 2);
    t = mul(t,t);
    if (k % 2){
        return mul(t, n);
    }
    return t;
}

struct dsu{
    int rt[maxN];
    int va[maxN];

    void init(){
        for (int i = 1; i <= n; i++){
            rt[i] = i;
            va[i] = fastpow(2,i);
        }
    }
    int find(int nu){
        if (nu == rt[nu]){
            return nu;
        }
        return rt[nu] = find(rt[nu]);;
    }  
    void com(int a, int b){
        rt[b] = a;
        va[a] = add(va[a], va[b]);
    }
};

int mk[maxN];

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
    int test;
    cin >> n >> test;
    dsu com[2];
    com[0].init();
    com[1].init();
    int ok = 0;
    while(test--){
        int t, a, b;
        cin >> t >> a >> b;
        t--;
        int u = com[t].find(a);
        int v = com[t].find(b);
        // cout << t << " " << u << " " << v << endl;
        if (u == v){
            goto bru;
        }
        if (u < v){
            swap(v,u);
        }
        if (mk[v]){
            ok--;
        }
        mk[v] = 0;
        com[t].com(u,v);
        if (u == com[1].find(u)){
            if (mk[u]){
                ok--;
            }
            mk[u] = (com[0].va[u] != com[1].va[u]);
            if (mk[u]){
                ok++;
            }
        }
        bru:;
        // for (int i = 1; i <= n; i++){
        //     cout << mk[i];
        // }
        // cout << endl;
        if (ok){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }
    }
    return 0;
}