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

const int maxN = 310;
const int mod = 1e9 + 9;
const int base = 40;

int a[maxN][maxN];
int b[3][maxN];
int pre[maxN][maxN];
int suf[maxN][maxN];
int inpow[maxN];
int po[maxN];

int add(int x, int y){
    return (x + y) % mod;
}

int sub(int x, int y){
    return (x - y + mod) % mod;
}

int mul(int x, int y){
    return (x * y) % mod;
}

int fpow(int nu, int x){
    if (x == 0){
        return 1;
    }
    if (x == 1){
        return nu;
    }
    int t = fpow(nu, x / 2);
    t = mul(t,t);

    if (x % 2){
        return mul(t,nu);
    }
    return t;
}

int divi(int x, int y){
    return mul(x, fpow(y, mod - 2));
}

int h[3][maxN];

int get(int t, int l, int r){
    if (t == 0){
        return sub(h[0][r], mul(h[0][l - 1], po[r - l + 1])); 
    }
    return sub(h[1][l], mul(h[1][r + 1], po[r - l + 1])); 
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("Debug.inp", "r")) {
        freopen("Debug.inp", "r", stdin);
        freopen("Debug.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char x;
            cin >> x;
            a[i][j] = x - '0';
        }
    }
    
    for (int i = 0; i <= 300; i++){
        inpow[i] = divi(1,fpow(2,i));
        po[i] = fpow(base, i);
    }
    for (int j = 1; j <= m; j++){
        for (int i = 1, t = 1; i <= n; i++){
            pre[i][j] = pre[i - 1][j];
            pre[i][j] = add(pre[i][j], mul(a[i][j], t));
            t = mul(t,2);
        }
    }

    for (int j = 1; j <= m; j++){
        for (int i = n, t = 1; i >= 1; i--){
            suf[i][j] = suf[i + 1][j];
            suf[i][j] = add(suf[i][j], mul(a[i][j], t));
            t = mul(t,2);
        }
    }

    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= m; j++){
    //         cout << suf[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int res = 1;
    for (int l = 1; l <= n; l++){
        for (int r = 1 + res; r <= n; r++){
            int le = r - l + 1;
            // cout << "With: " << l << " " << r << endl;
            for (int i = 1; i <= m; i++){
                b[0][i] = sub(pre[r][i], pre[l - 1][i]);
                b[0][i] = mul(b[0][i], inpow[l - 1]);

                b[1][i] = sub(suf[l][i], suf[r + 1][i]);
                b[1][i] = mul(b[1][i], inpow[n - r]);
            }
            // for (int i = 1; i <= m; i++){
            //     cout << b[0][i] << " ";
            // }
            // cout << endl;
            // for (int i = 1; i <= m; i++){
            //     cout << b[1][i] << " ";
            // }
            // cout << endl;

            for (int i = 1; i <= m; i++){
                h[0][i] = add(mul(h[0][i - 1], base), b[0][i]);
            }
            for (int i = m; i >= 1; i--){
                h[1][i] = add(mul(h[1][i + 1], base), b[1][i]);
            }
            
            for (int i = 1; i <= m; i++){
                if (get(0,i,i + le - 1) == get(1,i, i + le - 1)){
                    res = max(res, le);
                }
            }

        }
    }
    if (res == 1){
        cout << -1 << endl;
        return 0;
    }
    cout << res << endl;
    return 0;
}