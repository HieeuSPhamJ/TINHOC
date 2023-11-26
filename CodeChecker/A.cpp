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

const int maxN = 1e3 + 10;
const int mod = 1e9 + 7;

int pre[maxN][maxN];
int a[maxN];

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
        t = mul(t,n);
    }
    return t;
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    // freopen("area.inp", "r", stdin);
    // freopen("output.OUT", "w", stdout);
    if (fopen("AREA.inp", "r")) {
        freopen("AREA.inp", "r", stdin);
        freopen("AREA.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        int x, y, l, r;
        cin >> x >> l >> y >> r;
        pre[x][l]++;
        pre[x][r + 1]--;
        pre[y + 1][l]--;
        pre[y + 1][r + 1]++;
    }
    int res = 0;
    for (int i = 1; i < maxN; i++){
        for (int j = 1; j < maxN; j++){
            pre[i][j] += pre[i][j - 1];
            a[j] += pre[i][j];
            if (a[j]){
                res = add(res, fastpow(mul(i,j),k));
                // cout << i << " " << j << " " << mul(j,j) << " " << fastpow(mul(i,j),k) << endl;
            }
        }
    }
    cout << res << endl;
    return 0;
}