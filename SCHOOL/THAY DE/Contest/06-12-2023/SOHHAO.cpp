#include"bits/stdc++.h"
#define int long long
// #define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e7 + 10;

int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("SOHHAO.inp", "r")) {
        freopen("SOHHAO.inp", "r", stdin);
        freopen("SOHHAO.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int l, r;
    cin >> l >> r;
    for (int i = 1; i + i <= r; i++){
        int j = max(i * (l / i), i + i);
        // cout << i << " " << j << endl;
        for (; j <= r; j+=i){
            a[j] += i;
        }
    }
    int res = 0;
    for (int i = l; i <= r; i++){
        res += abs(a[i] - i);
        // cout << i << " " << a[i] << " " << i - a[i] << endl;
    }
    cout << res << endl;
    return 0;
}