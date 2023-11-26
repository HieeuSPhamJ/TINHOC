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

const int maxN = 1e5 + 10;

int N,k;

const int mod = 1e9 + 7;

int f[maxN];
int fact[maxN];
int nfact[maxN];
int infact[maxN];
int innfact[maxN];

int add(int a, int b){
    return (a + b) % mod;
}

int mul(int a, int b){
    return (a * b) % mod;
}

int sub(int a, int b){
    return (a - b + mod) % mod;
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
        t = mul(t,n);
    }
    return t;
}

int divi(int a, int b){
    return mul(a, fastpow(b,mod - 2));
}

int cal(int n){
    // cout << endl;
    if (n <= k + 2){
        return f[n];
    }
    int tu = 1;
    for (int i = 1; i <= k + 2; i++){
        tu = mul(tu, n - i);
    }
    int res = 0;
    for (int i = 1; i <= k + 2; i++){
        int p = 1;
        int mau = n - i;
        mau = mul(mau, innfact[k + 2 - i]);
        mau = mul(mau, infact[i - 1]);
        res = add(res, mul(f[i], divi(tu, mau)));
    }
    return res;
}

int cost(int l, int r){
    // return r - l + 1;
    return sub(cal(r), cal(l - 1));
}

struct node{
    int re = 0;
    int va = 0;
    int in = 0;
};

struct seg{
    node seg[4 * maxN];
    void build(int id = 1, int l = 1, int r = N){
        if (r < l){
            return;
        }
        seg[id].in = 0;
        seg[id].va = cost(l,r);
        // cout << l << " " << r << " " << cost(l,r) << endl;
        seg[id].re = 0;
        if (l == r){
            return;
        }
        int mid = (l + r) / 2;
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
    }
    
    void update(int L, int R, int v, int id = 1, int l = 1, int r = N){
        if (L > R){
            return;
        }
        if (r < L or R < l){
            return;
        }
        if (L <= l and r <= R){
            seg[id].in += v;
            if (seg[id].in > 0){
                seg[id].re = seg[id].va;
            }
            else if (l != r){
                seg[id].re = (seg[2 * id].re + seg[2 * id + 1].re) % mod;
            }
            else if (l == r){
                seg[id].re = 0;
            }
            // cout << l << " " << r << ": " << seg[id].re << " " << seg[id].in << endl;
            return;
        }

        int mid = (l + r) / 2;

        update(L, R, v, 2 * id, l, mid);
        update(L, R, v, 2 * id + 1, mid + 1, r);
        
        if (seg[id].in > 0){
            seg[id].re = seg[id].va;
        }
        else if (l != r){
            seg[id].re = (seg[2 * id].re + seg[2 * id + 1].re) % mod;
        }
        else if (l == r){
            seg[id].re = 0;
        }
        
        // cout << l << " " << r << ": " << seg[id].re << " " << seg[id].in << endl;
    }

} seg;

void init(){
    fact[0] = 1;
    nfact[0] = 1;
    for (int i = 1; i <= k + 2; i++){
        fact[i] = mul(fact[i - 1], i);
        nfact[i] = mul(nfact[i - 1], -i);
        f[i] = f[i - 1] + fastpow(i, k);
    }
    infact[k + 2] = divi(1,fact[k + 2]);
    innfact[k + 2] = divi(1,nfact[k + 2]);
    for (int i = k + 1; i >= 1; i--){
        infact[i] = mul(infact[i + 1], i + 1);
        innfact[i] = mul(innfact[i + 1], i + 1);
    }
}

vector <pair<ii,int>> sto[maxN];

signed main(){
    // freopen("input.inp", "r", stdin);
    // freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("AREA.inp", "r")) {
        freopen("AREA.inp", "r", stdin);
        freopen("AREA.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cin >> k;
    for (int i = n; i >= 1; i--){
        int x, y, l, r;
        cin >> x >> l >> y >> r;
        sto[x].push_back({{l,r}, 1});
        sto[y + 1].push_back({{l,r}, -1});
        N = max(N, r);
        n = max(n,y + 1);
    }
    init();
    seg.build();
    int res = 0;
    for (int i = 1; i <= n; i++){
        // cout << "With: " << i << endl;
        for (auto x: sto[i]){
            // cout << "update: " << x.fi.fi << " " << x.fi.se << " " << x.se << endl;
            seg.update(x.fi.fi, x.fi.se, x.se);
        }
        // cout << seg.seg[1].re << endl;
        res = add(res, mul(fastpow(i,k),seg.seg[1].re));
        // res += seg.seg[1].re;
    }

    cout << res << endl;

    return 0;
}
