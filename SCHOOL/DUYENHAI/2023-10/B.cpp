#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 5e6 + 10;
const int mod = 1e9 + 7;
const int base = 50;

int n, m;
vector <int> a, b;
vector <int> ha[3];
int POW[(int)1e5];
 
int mul(int a, int b){
    (a *= b) %= mod;
    return a;
}
 
int add(int a, int b){
    (a += b) %= mod;
    return a;
}
 
int subtr(int a, int b){
    (a = a - b + mod) %= mod;
    return a;
}
 
void print(ii a){
    cout << a.fi << " " << a.se << endl;
}
 
void init(){
    POW[0] = 1;
    for (int i = 1; i <= max(n,m); i++){
        POW[i] = mul(POW[i - 1], base);
    }
    ha[0].resize(n + 2);
    ha[1].resize(m + 2);
    
    ha[0][0] = 0;
    ha[1][0] = 0;
    for (int i = 1; i <= n; i++){
        ha[0][i] = add(mul(ha[0][i - 1],base), a[i] + 3);
        // cout << ha[0][i].fi << " " << ha[1][i].fi << endl;
        // print({a[i] + 3,a[i] + 3});
    }
    for (int i = 1; i <= m; i++){
        ha[1][i] = add(mul(ha[1][i - 1],base), b[i] + 3);
        // cout << ha[0][i].fi << " " << ha[1][i].fi << endl;
        // print({a[i] + 3,a[i] + 3});
    }
}   

int get(int t, int l, int r){
    if (t == 0 and r > n){
        return 0;
    }
    if (t == 1 and r > m){
        return 0;
    }
    int th = subtr(ha[t][r], mul(ha[t][l - 1], POW[r - l + 1]));
    return th;
}

map <int,int> cnt[(int)(1e5)];

signed main(){
    // freopen("btab.INP", "r", stdin);
    // freopen("btab.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    a.resize(n + 2);
    b.resize(m + 2);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++){
        cin >> b[i];
    }
    if (n >= m){
        swap(n,m);
        swap(a,b);
    }
    init();
    // cout << get(0,2,3) << endl;
    for (int i = 1; i <= n; i++){
        for (int j = i, z = 0, o = 0, no = 0; j <= n; j++){
            if (a[j] == 1){
                o++;
            }
            else if (a[j] == 0){
                break;
            }
            else{
                no++;
            }
            // cout << no << " " << z << " " << o << endl;
            if (z == 0 and no * no + o * o - no * o - o * no == 0){
                cnt[j - i + 1][get(0,i,j)]++;
                // cout << i << " " << j << endl;
            }
        }
    }

    // cout << get(0,2,3).fi << " " << get(1,3,4).fi << endl;

    int res = 0;
    for (int len = 1; len <= n; len++){
        for (auto i: cnt[len]){
            int conhash = i.fi;
            int numa = i.se;
            int numb = 0;
            // cout << len << ": " << conhash << endl;
            for (int i = 1; i <= m - len + 1; i++){
                if (get(1,i,i + len - 1) == conhash){
                    // cout << i << " " << i + len - 1 << endl;
                    numb++;
                }
            }
            res += numa * numb;
        }
    }
    cout << res << endl;
    return 0;
}
